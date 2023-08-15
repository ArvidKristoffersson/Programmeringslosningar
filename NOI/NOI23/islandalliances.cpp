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
#include <unordered_set>

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

const int MAXN = 1e5+2;
set<int> adj[MAXN];
set<int> selfNode[MAXN];
int parent[MAXN], sill[MAXN];

int rootOf(int x){
    if (x == parent[x]){
        return x;
    }
    return parent[x] = rootOf(parent[x]);
}

bool joinTree(int a, int b){
    if (sill[a] < sill[b])swap(a, b);

    for (auto e : adj[b]){
        if (selfNode[a].find(e) != selfNode[a].end()){
            return false;
        }
    }

    sill[a] += sill[b];
    parent[b] = a;
    for (auto e : selfNode[b]){
        selfNode[a].insert(e);
    }
    for (auto e : adj[b]){
        adj[a].insert(e);
    }
    return true;
}

bool isSameTree(int a, int b){
    return rootOf(a) == rootOf(b);
}

int main(){
    scoobydoobydoo();
    vector<string> ans;
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 0; i < n; i++){
        parent[i] = i;
        selfNode[i].insert(i);
        sill[i] = 1;
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        int bRoot = rootOf(b);
        int aRoot = rootOf(a);
        if (!joinTree(aRoot, bRoot)){
            ans.push_back("REFUSE");
        } else {
            ans.push_back("APPROVE");
        }
        
    }


    for (auto e : ans){
        cout << e << endl;
    }


    return 0;
}
