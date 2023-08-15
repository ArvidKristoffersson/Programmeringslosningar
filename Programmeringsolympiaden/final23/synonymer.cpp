#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}


vector<int> adj[5001];
bool isVisited[5001];
map<string, int> nodeFind;
map<int, string> conv;
map<int, string> alreadyFound;
bool done = false;

string dfs(int w, int node){
    if (w == 2){
        done = true;
        return conv[node];
    }
    isVisited[node] = true;

    string ret = "";

    for (auto e : adj[node]){
        if (!isVisited[e] && !done){
            ret = dfs(w+1, e);
        }
    }


    return ret;
}

int main(){
    scoobydoobydoo();
    ll n; cin >> n;
    vector<pair<string, string> > v(n);
    int count = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        if (nodeFind.find(v[i].first) == nodeFind.end()){
            nodeFind[v[i].first] = count;
            conv[count] = v[i].first;
            count++;
        }
        if (nodeFind.find(v[i].second) == nodeFind.end()){
            nodeFind[v[i].second] = count;
            conv[count] = v[i].second;
            count++;
        }
        
    }

    for (auto e : v){
        adj[nodeFind[e.first]].push_back(nodeFind[e.second]);
        adj[nodeFind[e.second]].push_back(nodeFind[e.first]);
    }

    int m; cin >> m;
    vector<string> ans;

    for (int i = 0; i < m; i++){
        string c; cin >> c;
        string s = dfs(0, nodeFind[c]);
        ans.push_back((s.size() == 0 ? c : s));
        for (int i = 0; i < 5001; i++){
            isVisited[i] = false;
        }
        done = false;
    }


    for (auto e : ans){
        cout << e << " ";
    }
    cout << endl;
    

    return 0;
}
