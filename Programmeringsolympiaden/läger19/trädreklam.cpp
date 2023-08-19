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

const int MAXN = 2001;
ll memo[MAXN][30001];
int n, b;
int parent[MAXN], nodeCost[MAXN], subSz[MAXN];
ll peopleBelow[MAXN];
bool isVisited[MAXN];
vector<pair<int, int>> adj[MAXN];

vector<int> nodesLine;


ll dp(int index, int moneys){
    if (memo[index][moneys] != -1){
        return memo[index][moneys];
    }
    if (index >= n || !moneys){
        return 0;
    }
    ll maxi = 0;
    int node = nodesLine[index];
    maxi = max(maxi, dp(index+1, moneys));
    if (moneys >= nodeCost[node]){
        maxi = max(maxi, dp(index+subSz[node], moneys-nodeCost[node])+peopleBelow[node]);
    }
    return memo[index][moneys] = maxi;
}


void initDP(){
    for (int i = 0; i < 2001; i++){
        for (int j = 0; j < 30001; j++){
            memo[i][j] = -1;
        }
    }
}


int buildTree(int node = 0){
    isVisited[node] = true;
    nodesLine.push_back(node);
    subSz[node] = 1;  
    for (auto& e : adj[node]){
        if (!isVisited[e.first]){
            subSz[node] += buildTree(e.first);
            peopleBelow[node] += peopleBelow[e.first];
            parent[e.first] = node;
            nodeCost[e.first] = e.second;
        }
    }
    return subSz[node];
}


int main(){
    scoobydoobydoo();
    cin >> n >> b;

    for (int i = 1; i < n; i++){
        int a; cin >> a; peopleBelow[i] = a;
    }

    for (int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    initDP();
    buildTree();

    cout << dp(1, b) << endl;


    return 0;
}
