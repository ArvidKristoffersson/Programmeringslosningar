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
vector<int> adj[MAXN];
int depth[MAXN];
bool isVisited[MAXN];
int firstBase = 0, maxDepth = -1;
 
void dfs(int node, int w){
    isVisited[node] = true;
    depth[node] = w;
    if (w > maxDepth){
        maxDepth = w;
        firstBase = node;
    }
    for (auto& e : adj[node]){
        if (!isVisited[e]){
            dfs(e, w+1);
        }
    }
    
    return;
}
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(0, 0);
 
    queue<pair<int, int> > q;
 
    q.push({firstBase, 0});
 
    for (int i = 0; i < n; i++){
        isVisited[i] = false;
    }
    isVisited[firstBase] = true;
 
    int lastWidth = 0;
 
    while (!q.empty()){
        int node = q.front().first;
        int w = q.front().second;
        lastWidth = w;
        q.pop();
 
        for (auto& e : adj[node]){
            if (!isVisited[e]){
                q.push({e, w+1});
                isVisited[e] = true;
            }
        }
    }
 
    cout << lastWidth << endl;
 
 
 
 
 
 
 
 
    return 0;
}
