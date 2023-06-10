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

const int MAXN = 1e5+1;

priority_queue<pair<int, int> > pq;
priority_queue<int> vals[MAXN];
vector<int> adj[MAXN];
bool isVisited[MAXN];
int neighbours[MAXN];
priority_queue<int> ans;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int rootTree(){
    int ret = -1;
    while (!pq.empty()){
        int w = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        int j = 0, maximus = -1;
        while (!vals[node].empty()){
            maximus = max(maximus, vals[node].top()+j);
            vals[node].pop();
            j++;
        }

        for (auto e : adj[node]){
            neighbours[e]--;
            if (!isVisited[e] || neighbours[e] == 0){
                vals[e].push(maximus+1);
            }
            if (neighbours[e] < 2 && !isVisited[e]){
                isVisited[e] = true;
                pq.push({-maximus-1, e});
            }
        }

        if (neighbours[node] == 0){
            ans.push(maximus);
        }
    }
    int j = 0;
    while (!ans.empty()){
        ret = max(ret, ans.top()+j);
        ans.pop();
    }

    return ret;
}
int n;

vector<int> leaves;
queue<int> c, calcQ;
int parent[MAXN], children[MAXN];
int minimus = 1e9+1;

int calculation(){
    for (auto e : leaves){
        if (parent[e] != -1) {
            vals[e].push(0);
            calcQ.push(e);
        }
    }

    while (!calcQ.empty()){
        int node = calcQ.front();
        int maximus = -1;
        int j = 0;
        calcQ.pop();
        while (!vals[node].empty()){
            maximus = max(maximus, vals[node].top()+j);
            vals[node].pop();
            j++;
        }
        if (parent[node] == -1){
            return maximus;
        }
        children[parent[node]]--;
        vals[parent[node]].push(maximus+1);
        if (children[parent[node]] == 0){
            calcQ.push(parent[node]);
        }
    }

    return -1;

}

void buildTree(int node){
    for (int i = 0; i < n; i++){
        parent[i] = -1;
        children[i] = 0;
        isVisited[i] = false;
    }
    isVisited[node] = true;
    c.push(node);
    while (!c.empty()){
        int cur = c.front();
        c.pop();
        for (auto e : adj[cur]){
            if (!isVisited[e]){
                isVisited[e] = true;
                parent[e] = cur;
                children[cur]++;
                c.push(e);
            }
        }

    }

    minimus = min(minimus, calculation());

}

int specialCase2(){
    for (auto e : leaves){
        while (!vals[e].empty())vals[e].pop();
    }
    for (int i = 0; i < n; i++){
        buildTree(i);
    }

    return minimus;
}

int main(){
    scoobydoobydoo();
    cin >> n;


    for (int i = 0; i < n; i++){
        int m; cin >> m;
        if (m == 1){
            pq.push({0, i});
            vals[i].push(0);
            isVisited[i] = true;
            leaves.push_back(i);
        }
        neighbours[i] = m;
        for (int j = 0; j < m; j++){
            int t; cin >> t;
            adj[i].push_back(t);
        }
    }

    if (n <= 250){
        cout << specialCase2() << endl;
        return 0;
    }

    cout << rootTree() << endl;


    return 0;
}
