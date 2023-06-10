#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

ll n, m, k; 
vector<pair<ll, ll> > fV, v;

bool itWork(ll q){
    if (q == 0)return true;
    ll lastHigh = 0;
    ll start = n;
    for (auto e : v){
        if (lastHigh == k)return false;
        if (lastHigh > e.second)continue;
        ll down = (lastHigh > e.first ? lastHigh : e.first);
        double a = e.second - down +1;
        ll z = ceil(a/q);
        start -= z;
        lastHigh = e.second - ((ll)(a-1)%q) + q;
        if (start <= 0)return true;
    }

    return false;
}

ll binarySearch(){
    ll fir = 0, sec = k+1;
    ll ret = -1;
    while (fir < sec){
        double k = ceil((double)(fir+sec)/2);
        if (itWork(k)){
            fir = k;
            ret = k;
        } else {
            sec = k-1;
        }
    }
    return ret;
}

vector<pair<ll, ll> > makeInput(vector<pair<ll, ll> > vec){
    vector<pair<ll, ll> > ret;
    ll lastHigh = vec[0].second;
    if (vec[0].first != 0)ret.push_back({0, vec[0].first-1});

    for (int i = 1; i < vec.size(); i++){
        pair<ll, ll> e = vec[i];
        if (lastHigh+1 < e.first)ret.push_back({lastHigh+1, e.first-1});
        lastHigh = e.second;
    }

    if (lastHigh != k-1){
        ret.push_back({lastHigh+1, k-1});
    }

    return ret;
}

int main(){

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        fV.push_back({a, b});
    }

    if (m == 0){
        v = {{0, k-1}};
    } else {
        sort(all(fV));
        v = makeInput(fV);
    }


    cout << binarySearch() << endl;


    return 0;
}
