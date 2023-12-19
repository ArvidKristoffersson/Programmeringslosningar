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

struct Node {
    int cycle;
    int modulo;
    int sz;
    int distanceToCycle;
    int tree;
    int lastParent;
    int index;
    Node(){
        cycle = -1;
        modulo = 0;
        sz = 0;
        distanceToCycle = 0;
        lastParent = 0;
        index = -1;
        tree = -1;
    }
};


const int MAXN = 1e5+1;
int parent[MAXN];
Node nodes[MAXN];
int isVisited[MAXN];
int binPar[MAXN][20];
vector<int> children[MAXN];
int numberCycle = 0;
int runCount = 1;
int numberTree = 0;
int n, q;

void initBinPar(){
    for (int i = 0; i < n; i++){
        binPar[i][0] = parent[i];
    }
    for (int j = 1; j < 20; j++){
        for (int i = 0; i < n; i++){
            binPar[i][j] = binPar[binPar[i][j-1]][j-1];
        }
    }
}

int jump(int node, int x){
    for (int i = 20; i >= 0; i--){
        if (x&(1<<i))node = binPar[node][i];
    }
    return node;
}

void giveCycle(int startNode){
    int endNode = startNode;
    int modi = 0;
    int siz = 1;
    vector<int> temp;
    temp.push_back(startNode);
    nodes[startNode].cycle = numberCycle;
    nodes[startNode].modulo = modi++;
    nodes[startNode].index = startNode;
    startNode = parent[startNode];
    while (startNode != endNode){
        siz++;
        temp.push_back(startNode);
        nodes[startNode].cycle = numberCycle;
        nodes[startNode].modulo = modi++;
        nodes[startNode].index = startNode;
        startNode = parent[startNode];
    }
    numberCycle++;
    for (auto& e : temp){
        nodes[e].sz = siz;
    }
    return;
}

void findCycle(int node){
    isVisited[node] = runCount;
    if (isVisited[parent[node]] == runCount){
        giveCycle(parent[node]);
    } else if (isVisited[parent[node]]){
        return;
    } else {
        findCycle(parent[node]);
    }

    return;
}

void initTrees(int node){
    nodes[node].tree = numberTree;
    nodes[node].distanceToCycle = nodes[parent[node]].distanceToCycle+1;
    nodes[node].lastParent = nodes[parent[node]].lastParent;
    for (auto& e : children[node]){
        initTrees(e);
    }
}


int main(){
    scoobydoobydoo();
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    for (int i = 0; i < n; i++){
        nodes[i];
    }

    for (int i = 0; i < n; i++){
        nodes[i].index = i;
        if (!isVisited[i])findCycle(i);
        runCount++;
    }

    for (int i = 0; i < n; i++){
        if (nodes[i].cycle == -1 && nodes[parent[i]].cycle != -1){
            nodes[i].tree = numberTree;
            nodes[i].distanceToCycle = 1;
            nodes[i].lastParent = parent[i];
            for (auto& e : children[i]){
                initTrees(e);
            }
            numberTree++;
        }
    }

    initBinPar();

    cin >> q;
    vector<int> ans;

    while (q--){
        int a, b; cin >> a >> b;
        a--; b--;
        if (nodes[a].cycle != -1 && nodes[b].cycle == -1){
            ans.push_back(-1);
        } else if (nodes[b].cycle == -1){
            if (nodes[b].tree != nodes[a].tree || nodes[b].distanceToCycle >= nodes[a].distanceToCycle || jump(a, nodes[a].distanceToCycle-nodes[b].distanceToCycle) != b)ans.push_back(-1);
            else ans.push_back(nodes[a].distanceToCycle-nodes[b].distanceToCycle);
        } else if (nodes[a].cycle != -1){
            if (nodes[a].cycle != nodes[b].cycle)ans.push_back(-1);
            else ans.push_back((nodes[b].modulo >= nodes[a].modulo ? nodes[b].modulo-nodes[a].modulo : nodes[a].sz-nodes[a].modulo+nodes[b].modulo)); 
        } else {
            int sum = nodes[a].distanceToCycle;
            a = nodes[a].lastParent;
            if (nodes[a].cycle != nodes[b].cycle)ans.push_back(-1);
            else ans.push_back((nodes[b].modulo >= nodes[a].modulo ? nodes[b].modulo-nodes[a].modulo : nodes[a].sz-nodes[a].modulo+nodes[b].modulo) + sum); 
        }
    }

    for (auto&e : ans){
        cout << e << endl;
    }

    return 0;
}
