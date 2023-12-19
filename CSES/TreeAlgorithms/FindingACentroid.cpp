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
 
const int MAXN = 2e5+1;
int subtreeSize[MAXN], n;
vector<int> adj[MAXN];
 
int buildTree(int node, int parent = 0){
    int ret = 1;
    for (auto& e : adj[node]){
        if (e != parent){
            ret += buildTree(e, node);
        }
    }
    return subtreeSize[node] = ret;
}
 
int centroid(int node, int parent = 0){
    for (auto& e : adj[node]){
        if (e != parent && subtreeSize[e]*2 > n)return centroid(e, node);
    }
    return node;
}
 
int main(){
    scoobydoobydoo();
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    buildTree(0);
    cout << centroid(0)+1 << endl;
 
    return 0;
}
