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
    buildTree(node*2, l, mid);
    buildTree(node*2+1, mid+1, r);
    return 0;   
}
 
void update(int x, int l, int r, int node = 1){
    if (leftOf[node] == l && rightOf[node] == r){
        ST[node] += x;
        return;
    }
 
    int a = 2*node; int b = 2*node+1;

    if (leftOf[a] <= l && rightOf[a] >= r){
        update(x, l, r, a);
        return;
    }
    if (leftOf[b] <= l && rightOf[b] >= r){
        update(x, l, r, b);
        return;
    }
 
 
    if (leftOf[a] <= l){
        update(x, l, rightOf[a], a);
    }
    if (rightOf[b] >= r){
        update(x, leftOf[b], r, b);
    }
 
    return;
}
 
 
ll query(int pos){
    if (pos == 0)return 0;
    return ST[pos] + query(pos/2);
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
            ll a; cin >> a;
            a--;
            ans.push_back(query(indexToNode[a]));
        } else {
            ll a, b, u; cin >> a >> b >> u;
            a--; b--;
            update(u, a, b);
        }
    }
    
 
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
    return 0;
}
