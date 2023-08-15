#include <iostream>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
 
#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
 
using namespace std;
 
typedef long long ll;
 
ll linf = 1e15+1;
 
inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
const int MAXN = 8e5+1;
ll ST[(4*MAXN)+1];
ll leftOf[MAXN], rightOf[MAXN], indexToNode[MAXN];
vector<ll> values;
 
ll buildTree(int node, int l, int r){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        indexToNode[l] = node;
        return ST[node] = values[l];
    }
    ll mid = (l+r)/2;
    ll leftMin = buildTree(node*2, l, mid);
    ll rightMin = buildTree(node*2+1, mid+1, r);
    return ST[node] = leftMin + rightMin;    
}
 
ll query(int l, int r, int node = 1){
    ll sum = 0;
    if (leftOf[node] == l && rightOf[node] == r){
        return ST[node];
    }
 
    int a = 2*node; int b = 2*node+1;
 
    if (leftOf[a] <= l && rightOf[a] >= r){
        return query(l, r, a);
    }
    if (leftOf[b] <= l && rightOf[b] >= r){
        return query(l, r, b);
    }
 
    if (leftOf[a] <= l){
        sum += query(l, rightOf[a], a);
    }
    if (rightOf[b] >= r){
        sum += query(leftOf[b], r, b);
    }
 
    return sum;
}
 
void updateTree(int node){
    if (node == 0)return;
    ST[node] = ST[node*2] + ST[node*2+1];
    updateTree(node/2);
}
 
void update(int pos, ll x){
    ST[pos] = x;
    updateTree(pos/2);
    return;
}
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
 
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        values.push_back(t);
    }
    vector<ll> ans;
 
    buildTree(1, 0, n-1);
 
    while (q--){
 
        int t; cin >> t;
 
        if (t == 2){
            ll a, b; cin >> a >> b;
            a--; b--;
            ans.push_back(query(a, b));
        } else {
            ll k, u; cin >> k >> u;
            k--;
            update(indexToNode[k], u);
        }
    }
 
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
 
 
    return 0;
}
