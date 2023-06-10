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

int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
    ll coins[51];
    vector<ll> products(m, 0);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    for (int j = 0; j < m; j++){
        cin >> products[j];
    }

    sort(rall(products));


    for (int i = 0; i < products.size(); i++){
        ll x = products[i];
        for (int j = n-1; j >= 0; j--){
            ll y = floor(x/pow(2, j));
            x -= min(y, coins[j])*pow(2, j);
            coins[j] -= min(y, coins[j]);
        }
        if (x > 0){
            cout << "nej" << endl;
            return 0;
        }
    }

    cout << "ja" << endl;
    



    return 0;
}
