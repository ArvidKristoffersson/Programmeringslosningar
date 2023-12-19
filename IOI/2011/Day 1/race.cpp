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
 
const int MAXN = 1e6+7;
bool isVisited[MAXN];
vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];
int subSz[MAXN];
int ans = 1e9+1;
int cnt[MAXN];
 
int subTreeSz(int node, int parent){
    subSz[node] = 1;
    for (auto& e : adj[node]){
        if (e.first != parent && !isVisited[e.first])subSz[node] += subTreeSz(e.first, node);
    }
    return subSz[node];
}
 
int centroidFind(int node, int parent, int target){
    for (auto& e : adj[node]){
        if (e.first != parent && !isVisited[e.first] && target <= subSz[e.first]){
            return centroidFind(e.first, node, target);
        }
    }
    return node;
}
 
void cleaning(int node, int parent, int w, int k){
    if (w > k)return;
    cnt[w] = 1e9;
    for (auto& e : adj[node]){
        if (e.first != parent && !isVisited[e.first]){
            cleaning(e.first, node, w+e.second, k);
        }
    }
}
 
void bfs(int node, int parent, int k, int w, bool filling, int depth = 1){
    if (w > k)return;
    if (filling)(cnt[w] = min(cnt[w], depth));
    else ans = min(ans, cnt[k-w]+depth);
    for (auto& e : adj[node]){
        if (e.first != parent && !isVisited[e.first]){
            bfs(e.first, node, k, w + e.second, filling, depth+1);
        }
    }
}
 
void centroidDecomp(int node, int k){
    node = centroidFind(node, -1, subTreeSz(node, -1)/2);
    isVisited[node] = true;
    cnt[0] = 0;
    for (auto& e : adj[node]){
        if (isVisited[e.first])continue;
        bfs(e.first, node, k, e.second, 0);
        bfs(e.first, node, k, e.second, 1);
    }
    cleaning(node, node, 0, k);
 
    for (auto& e : adj[node]){
        if (!isVisited[e.first])centroidDecomp(e.first, k);
    }
}
 
int best_path(int N, int K, int H[][2], int L[]){
    for (int i = 0; i <= K; i++){
        cnt[i] = 1e9;
    }
    for (int i = 0; i < N-1; i++){
        adj[H[i][0]].push_back({H[i][1], L[i]});
        adj[H[i][1]].push_back({H[i][0], L[i]});
    }
    centroidDecomp(0, K);
    return (ans < 1e8 ? ans : -1);
}
