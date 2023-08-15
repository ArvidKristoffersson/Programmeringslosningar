#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
 
#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
 
typedef long long ll;
 
ll linf = 1e15+1;
 
using namespace std;
 
inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
const int MAXN = 8e5+1;
vector<ll> adj[MAXN];
ll subSz[MAXN], ind[MAXN], ind2[MAXN];
ll worth[MAXN];
int i = 0;
vector<ll> arr;
bool isVisited[MAXN];
ll ST[4*MAXN];
ll leftOf[MAXN];
ll rightOf[MAXN];
 
void build(int l, int r, int node){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node] = arr[l];
        ind[l] = node;
    }
    else {
        int mid = (l+r)/2;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        ST[node] = ST[node*2] + ST[node*2+1];
 
    }
    return;
}
 
void updateW(int pos){
    ST[pos] = ST[2*pos] + ST[2*pos+1];
    if (pos == 1)return;
    updateW(pos/2);
    return;
}
 
void update(int pos, ll val){
    ST[ind[pos]] = val;
    updateW(ind[pos]/2);
    return;
}
 
 
ll dfs(int node){
    isVisited[node] = true;
    ind2[node] = i;
    arr[i++] = worth[node];
    subSz[node] = 0;
 
    for (auto& e : adj[node]){
        if (!isVisited[e]){
            subSz[node] += dfs(e);
        }
    }
    return ++subSz[node];
}
 
ll query(int l, int r, int node = 1){
    ll sum = 0;
 
    if (leftOf[node] == l && rightOf[node] == r){
        return ST[node];
    }
 
    int a = node*2;
    int b = node*2+1;
 
    if (leftOf[a] <= l && rightOf[a] >= r){
        return query(l, r, a);
    }
    if (leftOf[b] <= l && rightOf[b] >= r){
        return query(l, r, b);
    }
 

    if (leftOf[b] <= r){
        sum += query(leftOf[b], r, b);
    }
    if (rightOf[a] >= l){
        sum += query(l, rightOf[a], a);
    }
    return sum;
}
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> worth[i];
    }
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i = 0; i < n; i++){
        arr.push_back(0);
    }
 
    dfs(0);
    build(0, n-1, 1);
 
    vector<ll> ans;
    while (q--){
        int t; cin >> t;
        if (t == 1){
            ll a, b; cin >> a >> b;
            a--; 
            update(ind2[a], b);
        } else {
            ll x; cin >> x;
            x--;
            ans.push_back(query(ind2[x], ind2[x] + subSz[x]-1));
        }
 
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
 
 
 
    return 0;
}
