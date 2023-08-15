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
int subSz[MAXN];
vector<int> adj[MAXN];
bool isVisited[MAXN];
ll sol[MAXN];
int n;
 
int dfs(int node, int w){
    isVisited[node] = true;
    subSz[node] = 0;
    sol[0] += w;
 
    for (auto& e : adj[node]){
        if (!isVisited[e])subSz[node] += dfs(e, w+1);
    }
 
    return ++subSz[node];
}
 
void dp(int node){
    isVisited[node] = true;
    for (auto& e : adj[node]){
        if (!isVisited[e]){
            sol[e] = sol[node] + n - 2*subSz[e];
            dp(e);
        }
    }
    return;
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
 
    dfs(0, 0);
 
    for (int i = 0; i < n; i++){
        isVisited[i] = false;
    }
 
 
 
    dp(0);
 
    for (int i = 0; i < n; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
 
 
 
 
    return 0;
}
