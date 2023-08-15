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

int main(){
    scoobydoobydoo();
    double n; cin >> n;
    vector<double> v;
    double dp[2][31];
    dp[0][0] = n;
    dp[1][0] = n;
    for (int i = 0; i < 30; i++){
        double a; cin >> a;
        v.push_back(a);
    }

    double maxValue = -1e12;

    for (int i = 0; i < v.size(); i++){
        dp[0][i+1] = max(dp[0][i]*(1+v[i]/100), dp[1][i]*(1+v[i]/100));
        dp[1][i+1] = max(dp[0][i]+v[i], dp[1][i]+v[i]);
        maxValue = max(maxValue, max(dp[0][i+1], dp[1][i+1]));
    }



    cout << fixed << setprecision(7);

    cout << maxValue << endl;

    return 0;
}
