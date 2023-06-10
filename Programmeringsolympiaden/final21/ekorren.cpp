#include <iostream>
#include <cmath>
#include <queue>
#include <vector>


using namespace std;

typedef long long ll;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 1e5+1;
bool isVisited[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];

void treeInitialize(){
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front();
        isVisited[cur] = true;
        q.pop();
        for (auto e : adj[cur]){
            if (!isVisited[e]){
                parent[e] = cur;
                q.push(e);
            }
        }
    }
    return;
}

int pathToRoot(int& node){
    if (!isVisited[node] || node == 1){
        return 0;
    }
    isVisited[node] = false;

    return pathToRoot(parent[node])+1;
}

int main(){
    scoobydoobydoo();
    int n, k; cin >> n >> k;
    vector<int> allNuts;
    int a, b; 
    int maximus = max(n, k);
    for (int i = 0; i < n+k-1; i++){
        if (i < k){
            cin >> a;
            allNuts.push_back(a);
        }
        else if (i < n-1+k){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

    }

    treeInitialize();

    int sum = 0;

    for (int& e : allNuts){
        sum += pathToRoot(e);
    }

    cout << sum*2 << endl;


    _Exit(0);
}
