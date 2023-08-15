#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define all(x)  (x).begin(), (x).end()

typedef long long ll;

using namespace std;

ll n, s;
vector<vector<ll>> v;

ll maximus = 1e15;

void binarySearch(ll t1, ll t2, ll k1, ll m1) {
  ll a = t1, b = t2, minimus;
  while (a <= b) {
    double q = a + b;
    ll k = floor(q / 2);
    if (k1*k+m1 >= s) {
        minimus = k;
        b = k - 1;
    } else {
        a = k + 1;
    } 
  }
  cout << minimus << endl;
  return;
}

int main(){
    cin >> n >> s;
    ll k = 0, m = 0;
    for (int i = 0; i < n; i++){
        ll l, h, t; cin >> l >> h >> t;
        v.push_back({t, l, h});
        k += h;
        m += l;
    }

    sort(all(v));

    ll lastHigh = 0;

    for (int i = 0; i < v.size(); i++){
        ll first = lastHigh;
        lastHigh = v[i][0];
        if (s <= k*lastHigh+m){
            binarySearch(first, lastHigh, k, m);
            return 0;
        }
        k -= v[i][2];
        m += lastHigh*v[i][2];
    }

    return 0;
}
