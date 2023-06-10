#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

const int MAXN = 1e5+1;
double m[MAXN];
double I[MAXN];
bool isVisited[MAXN];
vector<int> children[MAXN];
vector<pair<int, double> > adj[MAXN];

int main(){
    int n; cin >> n;
    vector<int> ans, v;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> m[i] >> k;
        for (int j = 0; j < k; j++){
            int q, w; cin >> q >> w;
            adj[i].push_back({q, w});
            isVisited[q] = true;
            children[q].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (!isVisited[i]){
            q.push(i);
            I[i] = 1e6;
        }
    }

    while (!q.empty()){
        int c = q.front();
        q.pop();
        if (I[c] >= m[c]){
            ans.push_back(c);
        }
        for (auto e : adj[c]){
            I[e.first] += min(I[c], m[c]) * e.second/100.0;
            children[e.first].pop_back();
            if (children[e.first].empty()){
                q.push(e.first);
            }
        }

    }


    sort(all(ans));

    for (auto e : ans){
        cout << e << " ";
    }
    cout << endl;







    return 0;
}
