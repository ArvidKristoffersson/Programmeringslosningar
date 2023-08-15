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
vector<int> adj[MAXN], leaves;
set<int> col[MAXN];
bool isVisited[MAXN];
int disti[MAXN];
 
void dfs(int node){
    isVisited[node] = true;
    for (auto e : adj[node]){
        if (!isVisited[e]){
            dfs(e);
            if (col[node].size() < col[e].size())swap(col[node], col[e]);
            for (auto e : col[e])col[node].insert(e);
        }
    }
 
    disti[node] = col[node].size();
}
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        col[i].insert(t);
    }
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(0);
    
    for (int i = 0; i < n; i++){
        cout << disti[i] << " ";
    }
    cout << endl;
 
 
 
    return 0;
}
