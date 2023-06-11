#include <iostream>

using namespace std; 

const int MAXN = 1e5+10;
double dp[2][MAXN];

int main(){
    int n; cin >> n;
    double q; cin >> q;
    dp[1][0] = 100;
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++){
        double t; cin >> t;
        dp[0][i] = max(dp[0][i-1], (dp[1][i-1]-q)/t);
        dp[1][i] = max(dp[1][i-1], (dp[0][i-1]*t)-q);
    }

    cout << dp[1][n] << endl;


    return 0;
}
