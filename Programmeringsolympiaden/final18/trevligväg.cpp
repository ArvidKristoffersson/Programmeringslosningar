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

const int MAXN = 1e5+1;
vector<pair<ll, ll> > adj[MAXN];
double mem[MAXN];

void resetMem(ll maxi){
    for (int i = 1; i < maxi; i++){
        mem[i] = -linf;
    }
    mem[0] = 0;
    return;
}

int main(){

    scoobydoobydoo();
    cout << fixed << setprecision(10);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
    }
    double a = 0, b = 1e9+1;
    while (a < b){
        if (abs(a-b) < 1e-6){
            break;
        }
        double k = (a+b)/2;
        resetMem(n+1);

        for (int i = 0; i < n; i++){
            //bool cool = true;
            for (auto e : adj[i]){
                //last = i;
                mem[e.first] = max<double>(mem[e.first], (double)e.second + mem[i] - k);
            }
            
        }
        
        double best = mem[n-1];


        if (best < 0)b = k;
        else a = k;

    }

    cout << a << endl;



    return 0;
}
