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
 
const int MAXN = 5e4+7;
ll shortestPath[MAXN][20][6];
vector<pair<ll, ll>> adj[MAXN];
ll bestAt[MAXN];
ll k, n, m, q; 
 
void initShortest(){
    for (int i = 0; i < MAXN; i++){
        for (auto& e : adj[i]){
            int node = e.first%k;
            int w = e.second;
            shortestPath[i][0][node] = w;
        }
    }
    for (int j = 1; j < 20; j++){
        for (int i = 0; i < n; i++){
            for (int target = 0; target < k; target++){
                ll best = 200000000000;
                for (int l = 0; l < k; l++){
                    if (shortestPath[i][j-1][l] != 0 && shortestPath[(i/k+(1<<(j-1)))*k+l][j-1][target] != 0){
                        best = min(best, shortestPath[(i/k+(1<<(j-1)))*k+l][j-1][target]+shortestPath[i][j-1][l]);
                    }
                }
                shortestPath[i][j][target] = (best < 10000000000 ? best : 0);
            }
        }
    }
 
}
 
vector<ll> needClear;
 
ll findBest(int node, int jumpDist, int target){
    if (jumpDist == 0)return 100000000000*(node != target);
    if (bestAt[node] != 0)return bestAt[node];
    needClear.push_back(node);
    for (int i = 18; i >= 0; i--){
        if (jumpDist&(1<<i)){   
            ll best = 1000000000000;
            for (int j = 0; j < k; j++){
                if (shortestPath[node][i][j]){
                    best = min(best, findBest((((node/k)+(1<<i))*k)+j, jumpDist^(1<<i), target)+shortestPath[node][i][j]);
                }
            }
            return bestAt[node] = best;
        }
    }
    return bestAt[node] = 1000000000000;
}
 
 
int main(){
    scoobydoobydoo();
    cin >> k >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back({b, t});
    }
    initShortest();
    vector<ll> ans;
 
    while (q--){
        int a, b; cin >> a >> b;
        int depthA = a/k;
        int depthB = b/k;
        if (a == b){
            ans.push_back(0);
            continue;
        }
        if (depthA >= depthB){
            ans.push_back(-1);
            continue;
        }
        int depthDiff = depthB-depthA;
 
        ll ret = findBest(a, depthDiff, b);
        ans.push_back((ret < 10000000000 ? ret : -1));
 
        for (ll x : needClear){
            bestAt[x] = 0;
        }
        needClear.clear();
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }

    return 0;
}
