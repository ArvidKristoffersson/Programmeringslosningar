#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <stack>

#pragma GCC optimize("Ofast,inline") 
#pragma GCC optimize ("unroll-loops")

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 2e5+1;
ll vals[MAXN];

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> vals[i];
        vals[i] += (i ? vals[i-1] : 0);
    }

    ll worstSoFar = 0;
    ll maximus = -linf;

    for (int i = 0; i < n; i++){
        maximus = max(maximus, vals[i]-worstSoFar);
        worstSoFar = min(worstSoFar, vals[i]);
    }

    cout << maximus << endl;

    return 0;
}
