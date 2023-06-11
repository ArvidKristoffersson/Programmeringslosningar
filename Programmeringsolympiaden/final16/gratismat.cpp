#include <iostream>
#include <queue>

using namespace std; 

const int MAXN = 1e6+1;

vector<int> adj[MAXN];
bool isThere[MAXN];
int ans = 0;

void bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for (int i = 0; i < adj[c].size(); i++){
            if (!isThere[adj[c][i]]){
                q.push(adj[c][i]);
            } else {
                ans++;
            }
        }
    }

    return;
}

int main(){
    int n, m, tI, s; cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> tI;
        adj[tI].push_back(i);
    }

    for (int i = 0; i < m; i++){
        cin >> tI;
        isThere[tI] = true;
    }


    bfs(0);

    cout << ans << endl;







    return 0;
}
