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

#pragma GCC optimize("Ofast,inline") 
#pragma GCC optimize ("unroll-loops")

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

const int MAXN = 3e5+1;
ll arr[MAXN];
ll bestLeft[MAXN], bestRight[MAXN];

int main(){
    scoobydoobydoo();
    int n; cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        arr[i] = (i == 0 ? v[i] : v[i] + arr[i-1]);
    }
    
    ll ans = max(v[0], v[n-1]);

    ll maxi = -linf;

    for (int i = n-1; i >= 0; i--){
        maxi = max(maxi, arr[i]);
        bestRight[i] = maxi - arr[i];
    }

    ll mini = min((ll)0, arr[0]);


    for (int i = 1; i < n-1; i++){
        mini = min(mini, arr[i]);
        bestLeft[i] = arr[i-1] - mini;
        ans = max(ans, min(bestLeft[i], bestRight[i])+v[i]);
    }

    cout << ans << endl;
    

    return 0;
