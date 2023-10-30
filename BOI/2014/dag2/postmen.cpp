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
 
const int MAXN = 5e5+1;
bool edgeVisited[MAXN];
vector<pair<int, int>> adj[MAXN];
bool isVisited[MAXN];
int startNode;
int neighIndex[MAXN];
 
vector<vector<int> > sols;
vector<int> temp;
 
int counter = 0;
 
bool dfs(int node, int usedEdge){
    edgeVisited[usedEdge] = true;
    if (isVisited[node]){
        startNode = node;
        return true;
    }

    isVisited[node] = true;
    while (neighIndex[node] < adj[node].size()){
        pair<int, int> e = adj[node][neighIndex[node]++];
        if (!edgeVisited[e.second]){
            bool ret = dfs(e.first, e.second);
            if (ret){
                temp.push_back(node);
                if (node == startNode){
                    sols.push_back(temp);
                    temp.clear();
                } else {
                    isVisited[node] = false;
                    return true;
                }
            }
        } else {
            counter++;
        }
    }
 
    isVisited[node] = false;
    return false;
}
 
int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
 
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i+1});
        adj[b].push_back({a, i+1});
    }
 
    for (int i = 1; i <= n; i++){
        if (!isVisited[i])dfs(i, 0);
    }
 
    for (auto& v : sols){
        for (auto& e : v){
            cout << e << " ";
        }
        cout << "\n";
    }
    
 
    return 0;
}
