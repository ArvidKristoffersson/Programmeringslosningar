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
int ST[(4*MAXN)+1];
int leftOf[MAXN], rightOf[MAXN], indexToNode[MAXN];
vector<int> values;
 
int buildTree(int node, int l, int r){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        indexToNode[l] = node;
        return ST[node] = values[l];
    }
    int mid = (l+r)/2;
    int leftMin = buildTree(node*2, l, mid);
    int rightMin = buildTree(node*2+1, mid+1, r);
    return ST[node] = min(leftMin, rightMin);    
}
 
int query(int l, int r, int node = 1){
    int mini = 2e9+1;
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
        mini = min(mini, query(l, rightOf[a], a));
    }
    if (rightOf[b] >= r){
        mini = min(mini, query(leftOf[b], r, b));
    }
 
    return mini;
}
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
 
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        values.push_back(t);
    }
    vector<int> ans;
 
    buildTree(1, 0, n-1);
 
    while (q--){
        int a, b; cin >> a >> b;
        a--; b--;
        ans.push_back(query(a, b));
    }
 
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
 
 
    return 0;
}
