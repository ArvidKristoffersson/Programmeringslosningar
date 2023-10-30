#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 2e7+1;
set<ll> comps[MAXN];
vector<ll> v;
ll mem[MAXN];

ll n, k;

ll dp(ll index){
    ll div = v[index];
    if (mem[index])return mem[index];
    if (div == k)return 1;

    ll nDiv = div+1;
    auto it = comps[nDiv].upper_bound(index);
    ll ret = 0;

    if (it == comps[nDiv].end()){
        ret = dp(*(comps[nDiv].begin())) + n - index + *(comps[nDiv].begin());
    } else {
        ret = dp(*it) + *it - index;
    }

    return mem[index] = ret;
    
}

int main(){
    scoobydoobydoo();
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
        comps[t].insert(i);
    }

    ll mini = linf;

    for (auto& e : comps[1]){
        mini = min(mini, dp(e));
    }

    cout << mini << endl;

    return 0;
}
