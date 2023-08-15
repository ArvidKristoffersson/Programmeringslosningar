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

int main(){
    scoobydoobydoo();
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> pref(n);
    sort(all(v));
    pref[0] = v[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i-1] + v[i];
    }
    vector<ll> ans;

    while (q--){
        ll b; cin >> b;
        ans.push_back(pref[b-1]);
    }


    for (auto e : ans){
        cout << e << endl;
    }




    return 0;
}
