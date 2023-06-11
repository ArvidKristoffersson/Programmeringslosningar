#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std; 
using pii = pair<int, int>;

const int MAXN = 1e4;
vector<vector<pii>> adj;
int d[MAXN], p[MAXN];
string str;


void djikstra(int s){
    fill(d, d+MAXN, MAXN);
    fill(p, p+MAXN, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});

    while(!q.empty()){
        int distV = q.top().first;
        int v = q.top().second;
        q.pop();
        if(distV != d[v])continue;
        for (int i = 0; i < adj[v].size(); i++){
            int len = adj[v][i].first;
            int to = adj[v][i].second;
            if (d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }

    cout << d[str.size()*2 + 1] << endl;
    return;
}

int main(){
    cin >> str;
    for (int i = 0; i < str.size()*2+3; i++){
        adj.push_back({{}});
    }
    for (int i = 1, j = 0; i <= str.size()*2, j < str.size(); i+=2, j++){
        char tC = str[j];
        adj[i].push_back({1, i+1});
        adj[i].erase(adj[i].begin());
        adj[i+1].push_back({1, i});
        adj[i+1].erase(adj[i+1].begin());
        if (tC == 'S'){
            adj[i+1].push_back({1, i+3});
            adj[i+3].push_back({1, i+1});
            adj[i].push_back({0, i+2});
            adj[i+2].push_back({0, i});
        } else if (tC == 'N'){
            adj[i+1].push_back({0, i+3});
            adj[i+3].push_back({0, i+1});
            adj[i].push_back({1, i+2});
            adj[i+2].push_back({1, i});
        } else {
            adj[i+1].push_back({1, i+3});
            adj[i+3].push_back({1, i+1});
            adj[i].push_back({1, i+2});
            adj[i+2].push_back({1, i});
        }
    }

    int i = str.size()*2 + 1;

    adj[i].push_back({1, i+1});
    adj[i].erase(adj[i].begin());
    adj[i+1].push_back({1, i});
    adj[i+1].erase(adj[i+1].begin());

    djikstra(1);

    return 0;
}
