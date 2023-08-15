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
 
const int MAXN = 2e5+1;
vector<pair<int, int>> adj[MAXN];
bool isVisited[MAXN];
 
int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
 
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
 
    priority_queue<pair<int, int>  > pq;
    pq.push({0, 0});
 
    set<int> s;
    for (int i = 0; i < n; i++){
        s.insert(i);
    }
 
    vector<int> edgeWeight;
 
 
    while (!pq.empty()){
        int node = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        if (isVisited[node])continue;

        edgeWeight.push_back(w);
        isVisited[node] = true;
        s.erase(node);
        if (!s.size()){
            ll sum = 0;
            for (auto e : edgeWeight){
                sum += e;
            }
            cout << sum << endl;
            return 0;
        }
 
        for (auto& e : adj[node]){
            if (!isVisited[e.second]){
                pq.push({-(e.first), e.second});
            }
        }
 
    }
 
 
    cout << "IMPOSSIBLE" << endl;
 
 
 
    return 0;
}
