#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define all(x)  (x).begin(), (x).end()
#define ll long long

using namespace std;

const int MAXN = 100005;

ll dp[MAXN];
ll day[MAXN];

int main(){
    dp[0] = 0;
    vector<pair<ll, int> > v;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> dp[i];
        dp[i] += dp[i-1];
    }

    for (int i = 0; i < q; i++){
        ll c; cin >> c;
        v.push_back({c, i});
    }

    sort(all(v));

    bool done = false;

    int j = 0;

    for (int i = 1; i <= n && !done; i++){
        while (v[j].first < dp[i]){
            day[v[j].second] = i;
            j++;
            if (j >= v.size()){
                done = true;
                break;
            }
        }
    }

    for (int i = 0; i < q; i++){
        if (day[i]){
            cout << day[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }



  return 0;
}
