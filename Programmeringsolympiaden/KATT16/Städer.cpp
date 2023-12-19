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

const int MAXN = 2e5+5;
bool isVisited[MAXN];
ll counter[MAXN];
int subSz[MAXN];
int q, needClear = 0;
ll ans = 0;
vector<int> adj[MAXN];

int subTreeSz(int node, int parent){
    subSz[node] = 1;
    for (auto& e : adj[node]){
        if (e != parent && !isVisited[e])subSz[node] += subTreeSz(e, node);
    }
    return subSz[node];
}

void numberOfPaths(int node, int parent, int depth, bool filling){
    if (depth > q)return;
    needClear = max(needClear, depth);
    if (filling)counter[depth]++;
    else ans += counter[q-depth];
    
    for (auto& e : adj[node]){
        if (!isVisited[e] && e != parent)numberOfPaths(e, node, depth+1, filling);
    }
    return;
}

int centroidFind(int node, int parent, int target){
    for (auto& e : adj[node]){
        if (e != parent && !isVisited[e] && target <= subSz[e]){
            return centroidFind(e, node, target);
        }
    }
    return node;
}

void centroidDecomp(int node){
    node = centroidFind(node, -1, subTreeSz(node, -1)/2);
    isVisited[node] = true;
    needClear = 0;
    for (auto& e : adj[node]){
        if (!isVisited[e]){
            numberOfPaths(e, node, 1, false);
            numberOfPaths(e, node, 1, true);
        }
    }

    for (int i = 1; i <= needClear; i++){
        counter[i] = 0;
    }

    for (auto& e : adj[node]){
        if (!isVisited[e])centroidDecomp(e);
    }
}

ll paths(int n, int k, int f[], int t[]){
    q = k;
    for (int i = 0; i < n-1; i++){
        adj[f[i]-1].push_back(t[i]-1);
        adj[t[i]-1].push_back(f[i]-1);
    }
    counter[0] = 1;
    centroidDecomp(0);
    return ans;
}

