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
ll depth[MAXN];
multiset<ll> ms[MAXN];
vector<int> adj[MAXN];
int D, n;
ll ans = -1;
 
void buildTree(int node, int parent, int w){
    depth[node] = w;
    for (auto& e : adj[node]){
        if (e != parent)buildTree(e, node, w+1);
    }
}   
 
void smallerToLarger(int node, int parent){
    ms[node].insert(depth[node]);
    for (auto& e : adj[node]){
        if (e != parent){
            smallerToLarger(e, node);
            while (true){
                if (ms[e].empty() || ms[node].empty())break;
                if (*ms[e].begin()+*ms[node].begin()-2*depth[node] >= D)break;
                if (*ms[e].begin() > *ms[node].begin())ms[node].erase(ms[node].begin());
                else ms[e].erase(ms[e].begin());
            }
            for (auto& x : ms[e]){
                ms[node].insert(x);
            }
            ms[e].clear();
        }
    }
    ans = max(ans, (ll)ms[node].size());
}
 
int main(){
    scoobydoobydoo();
    cin >> n >> D;
    for (int i = 1; i < n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    buildTree(0, 0, 0);
    smallerToLarger(0, 0);
    cout << ans << endl;
 
    return 0;
}
