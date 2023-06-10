//52.02 poäng
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

priority_queue<pair<double, ll> > pq;

const int MAXN = 1e5+1;
vector<ll> adj[MAXN];
ll childs[MAXN];
double worth[MAXN], times[MAXN];

int main(){
    scoobydoobydoo();
    int c; cin >> c;
    int n, T; cin >> n >> T;

    for (int i = 0; i < n; i++){
        double t, v, k; cin >> t >> v >> k;
        childs[i] = k;
        worth[i] = v;
        times[i] = t;
        if (k == 0){
            pq.push({v/t, i});

        }
        for (int j = 0; j < k; j++){
            int a; cin >> a;
            adj[a].push_back(i);
        }
    }
    vector<ll> ans;
    while (T && !pq.empty()){
        ll node = pq.top().second;
        pq.pop();
        if (T - times[node] < 0)continue;
        T -= times[node];
        
        ans.push_back(node);
        for (auto e : adj[node]){
            childs[e]--;
            if (!childs[e]){
                pq.push({((worth[e]/times[e])*(1+10*adj[e].size()/n)), e});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto e : ans){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
