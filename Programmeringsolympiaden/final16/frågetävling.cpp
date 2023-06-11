#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

using namespace std;
vector<vector<ll>> groups;
map<pair<ll, ll>, ll> M;

ll dp(ll group, ll q_left, ll profit, ll b){
    if (group == groups.size())return profit;
    if (M[{group, q_left}])return M[{group, q_left}]+profit;

    ll newProfit = 0;
    ll used = 0;
    ll ret = 0;

    ret = max(ret, dp(group+1, q_left, profit, b));

    for (int i = 0; i < groups[group].size(); i++){
        newProfit += groups[group][i];
        used++;
        if (i == groups[group].size()-1){
            newProfit += b;
        }
        if (q_left-used < 0)break;

        ret = max(ret, dp(group+1, q_left-used, profit+newProfit, b));
    }
    M[{group, q_left}] = ret - profit;
    return ret;
}


int main(){
    ll n, m, k, b; cin >> n >> m >> k >> b;
    for (int i = 0; i < m; i++){
        groups.push_back({});
    }
    for (int i = 0; i < n; i++){
        ll a, t; cin >> a >> t;
        groups[t-1].push_back(a);
    }

    for (int i = 0; i < groups.size(); i++){
        sort(rall(groups[i]));
    }

    cout << dp(0, k, 0, b) << endl;

    return 0;
}
