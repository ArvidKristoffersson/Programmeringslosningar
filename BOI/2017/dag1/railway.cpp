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
 
const int MAXN = 1e5+1;
set<pair<int, int> > s[MAXN];
int wutS[MAXN];
vector<int> children[MAXN];
int n, m, k;
int q = 0;
vector<pair<int, int>> adj[MAXN];
int nodeId[MAXN], binPar[MAXN][20];
vector<pair<int, int> > elemsNode[MAXN];
vector<pair<int, int>> ans;
pair<int, int> eulerTour[MAXN];
int counter = 0;
int depthNode[MAXN];
 
void rootTree(int node, int parent, int depth){
    depthNode[node] = depth;
    eulerTour[node].first = counter++;
    for (auto& e : adj[node]){
        if (e.first != parent){
            children[node].push_back(e.first);
            nodeId[e.first] = e.second;
            binPar[e.first][0] = node;
            rootTree(e.first, node, depth+1);
        }
    }
    eulerTour[node].second = counter++;
}
 
void smallerToLarger(int node, int depth){
    if (children[node].size() == 0){
        wutS[node] = q;
        for (auto& e : elemsNode[node]){
            s[q].insert(e);
        }
        ans.push_back({s[q].size(), node});
        q++;
        
        return;
    }
    int maxiChild = -1, maxi = -1;
    for (auto& e : children[node]){
        smallerToLarger(e, depth+1);
        int sZ = s[wutS[e]].size();
        if (sZ > maxi){
            maxiChild = e;
            maxi = s[wutS[e]].size();
        }
    }
 
 
    wutS[node] = wutS[maxiChild];
    for (auto& e : children[node]){
        if (e != maxiChild){
            for (auto& l : s[wutS[e]]){
                s[wutS[node]].insert(l);
            }
        }
    }
 
    
    for (auto& e : elemsNode[node]){
        s[wutS[node]].insert(e);
    }
 
    while (true){
        auto it = s[wutS[node]].lower_bound({depth, -1});
        if (it == s[wutS[node]].end())break;
        s[wutS[node]].erase(it);
    }

    ans.push_back({s[wutS[node]].size(), node});
    
    return;
}
 
 
void initBinPar(){
    binPar[0][0] = 0;
    for (int j = 1; j < 20; j++){
        for (int i = 0; i < n; i++){
            binPar[i][j] = binPar[binPar[i][j-1]][j-1];
        }
    }
    return;
}
 
int jump(int node, int x){
    for (int i = 20; i >= 0; i--){
        if (x & (1<<i))node = binPar[node][i];
    }
    return node;
}
 
int lca(vector<int> v){
    int minIn = 1e9, maxOut = -100;
    for (int x : v){
        minIn = min(minIn, eulerTour[x].first);
        maxOut = max(maxOut, eulerTour[x].second);
    }
    for (int x : v){
        if (eulerTour[x].first == minIn && eulerTour[x].second == maxOut)return depthNode[x];
    }
    int node = v[0];
    for (int i = 18; i >= 0; i--){
        int anc = binPar[node][i];
        if (eulerTour[anc].first > minIn || eulerTour[anc].second < maxOut)node = anc;
    }
    node = binPar[node][0];
    return depthNode[node];
}
int main(){
    scoobydoobydoo();
    cin >> n >> m >> k;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, i+1});
        adj[b].push_back({a, i+1});
    }
 
    rootTree(0, 0, 0);
    initBinPar();
 
    for (int i = 0; i < m; i++){
        int l; cin >> l;
        vector<int> v;
        for (int j = 0; j < l; j++){
            int t; cin >> t;
            v.push_back(--t);
        }
        int d = lca(v);
        for (int x : v){
            elemsNode[x].push_back({d, i});
        }
    }

    smallerToLarger(0, 0);
 
    sort(rall(ans));
 
    vector<int> nAns;
    for (int i = 0; i < ans.size() && ans[i].first >= k; i++){
        nAns.push_back(nodeId[ans[i].second]);
    }
 
    sort(all(nAns));
 
    cout << nAns.size() << endl;
    for (auto& e : nAns){
        cout << e << " ";
    }
    cout << endl;
 
    return 0;
}
