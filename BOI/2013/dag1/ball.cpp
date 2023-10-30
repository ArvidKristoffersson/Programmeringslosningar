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
int parent[MAXN];
int binPar[MAXN][20];
vector<int> children[MAXN];
int childs[MAXN];
int vals[MAXN];
int minInSubtree[MAXN];
int root;
int indexToVal[MAXN];
int valToIndex[MAXN];
int hasBall[MAXN];
int indexToNode[MAXN];
int nodeToIndex[8*MAXN];
 
int initMinInSubtree(int node = root){
    int mini = node;
    for (auto& e : children[node]){
        mini = min(mini, initMinInSubtree(e));
    }
    return minInSubtree[node] = mini;
}
 
int x = 0;
int n, q; 
 
void initVals(int node = root){
    set<pair<int, int>> s;
    for (auto& e : children[node]){
        s.insert({minInSubtree[e], e});
    }
    
    for (auto& p : s){
        initVals(p.second);
    }
    indexToVal[x] = node;
    valToIndex[node] = x;
    vals[x++] = node;
    return;
}
 
void initBinPar(){
    for (int i = 1; i <= n; i++){
        binPar[i][0] = parent[i];
    }
 
    for (int j = 1; j < 20; j++){
        for (int i = 1; i <= n; i++){
            binPar[i][j] = binPar[binPar[i][j-1]][j-1];
        }
    }
    return;
}
 
pair<int, int> lastBallParent(int node){
    if (!hasBall[parent[node]])return {node, 0};
 
    int rolledBalls = 0;
    
    for (int i = 19; i >= 0; i--){
        if (hasBall[binPar[node][i]]){
            node = binPar[node][i];
            rolledBalls += (1 << i);
        }
    }
    return {node, rolledBalls};
}
 
int ST[8*MAXN];
int leftOf[8*MAXN], rightOf[8*MAXN];
 
void buildTree(int l, int r, int node = 1){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node] = 0;
        indexToNode[l] = node;
        nodeToIndex[node] = l;
        return;
    }
    int mid = (l+r)/2;
    buildTree(l, mid, 2*node);
    buildTree(mid+1, r, 2*node+1);
    ST[node] = 0;
}
 
void update1(int node){
    if (node == 0)return;
    ST[node] = min(ST[2*node], ST[2*node+1]);
    return update1(node/2);
}
 
void update(int node, int w){
    node = indexToNode[node];
    ST[node] = w;
    update1(node/2);
}
 
int closestEmpty(int node = 1){
    if (leftOf[node] == rightOf[node]){
        return nodeToIndex[node];
    }
    int a = 2*node, b = 2*node+1;
    if (ST[a] == 0)return closestEmpty(a);
    return closestEmpty(b);
}
 
int main(){
    scoobydoobydoo();
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> parent[i];
        children[parent[i]].push_back(i);
        childs[parent[i]]++;
        if (parent[i] == 0){
            root = i;
        }
    }
    initMinInSubtree();
    initVals();
    initBinPar();
    buildTree(0, n-1);
 
    vector<ll> ans;
 
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int k; cin >> k;
            int latest = -1;
            for (int i = 0; i < k; i++){
                int ind = closestEmpty();
                latest = ind;
                hasBall[indexToVal[ind]] = 1;
                update(ind, 1);
            }
            ans.push_back(indexToVal[latest]);
        } else {
            int x; cin >> x;
            pair<int, int> ballParent = lastBallParent(x);
            int indToRemove = valToIndex[ballParent.first];
            update(indToRemove, 0);
            hasBall[ballParent.first] = 0;
            ans.push_back(ballParent.second);
        }
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
    
    return 0;
}
