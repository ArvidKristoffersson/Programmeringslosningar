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

vector<pair<ll, ll> > v;
vector<pair<ll, ll> > endi;
map<pair<ll, ll>, bool> exists;
ll n, m, t;
map<pair<ll, ll>, ll> dp, val;
map<pair<ll, ll>, bool> isVisited;
priority_queue<pair<ll, pair<ll, ll> > > pq;
int main(){
    scoobydoobydoo();
    cin >> n >> m >> t;
    for (int i = 0; i < t; i++){
        ll a, b; cin >> a >> b;
        if (a == n-2){
            endi.push_back({a, b});
        }
        dp[{a, b}] = i+1;
        v.push_back({a, b});
        if (a == 1){
            pq.push({-(i+1), {a, b}});
        }
        exists[{a, b}] = true;

    }

    while (!pq.empty()){
        ll w = -pq.top().first;
        ll x = pq.top().second.first;
        ll y = pq.top().second.second;
        pq.pop();
        if (!isVisited[{x, y}]){
            dp[{x, y}] = max(dp[{x, y}], w);
            isVisited[{x, y}] = true;
            ll q = dp[{x, y}];
            if (!isVisited[{x, y-1}] && exists[{x, y-1}]){
                pq.push({-q, {x, y-1}});
            }
            if (!isVisited[{x, y+1}] && exists[{x, y+1}]){
                pq.push({-q, {x, y+1}});
            }
            if (!isVisited[{x+1, y}] && exists[{x+1, y}]){
                pq.push({-q, {x+1, y}});
            }
            if (!isVisited[{x-1, y}] && exists[{x-1, y}]){
                pq.push({-q, {x-1, y}});
            }
        }
    }

    ll miniVal = linf; 

    for (int i = 0; i < endi.size(); i++){
        if (isVisited[{endi[i]}])miniVal = min(miniVal, dp[{endi[i].first, endi[i].second}]);
    }


    if (miniVal == linf){
        cout << "nej" << endl;
    } else {
        cout << miniVal << endl;
    }

    return 0;
}
