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
 
int depth[MAXN], parent[MAXN], bPar[MAXN][31];
vector<int> adj[MAXN];
bool isVisited[MAXN];
 
void buildTree(int node, int w){
    isVisited[node] = true;
    depth[node] = w;
    for (auto e : adj[node]){
        if (isVisited[e])continue;
        parent[e] = node;
        buildTree(e, w+1);
    }
}
 
int jump(int x, int d){
    for (int i = 0; i < 31; i++){
        if (d & (1 << i))x = bPar[x][i];
    }
    return x;
}
 
int LCA(int a, int b){
    if (depth[a] < depth[b])swap(a, b);
 
    a = jump(a, depth[a] - depth[b]);
    if (a == b)return a;
 
    for (int i = 30; i >= 0; i--){
        int aT = bPar[a][i];
        int bT = bPar[b][i];
        if (aT != bT){
            a = aT;
            b = bT;
        }
    }
    return bPar[a][0];
}
 
int n, q;
 
void initB(){
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < 31; j++){
            bPar[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++){
        bPar[i][0] = parent[i];
    }
 
    for (int l = 1; l < 31; l++){
        for (int i = 0; i < n; i++){
            if (bPar[i][l-1] != -1){
                bPar[i][l] = bPar[bPar[i][l-1]][l-1];
            }
        }
    }
}
 
int main(){
    scoobydoobydoo();
    cin >> n >> q;
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);   
    }
 
    buildTree(0, 0);
    parent[0] = 0;
    initB();
 
    vector<int> ans;
 
    while (q--){
        int x, y; cin >> x >> y;
        x--; y--;
        ans.push_back((depth[x] + depth[y] - 2*depth[LCA(x, y)]));
    }
 
    for (auto e : ans){
        cout << e << endl;
    }
 
 
 
 
    return 0;
}
