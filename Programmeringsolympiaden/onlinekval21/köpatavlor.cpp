#include <iostream>

using namespace std; 

const int MAXN = 2*1e3+1;
long long dp[MAXN][MAXN];
long long cost[MAXN];

int main(){
    int n, k; cin >> n >> k;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = 1e9+1;
        }
    }


    for (int i = 0; i < n; i++){
        cin >> cost[i];
        dp[i][0] = cost[i];
    }


    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < k-1; j++){
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+cost[i+1]+1);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        }
    }

    long long minimus = 1e9+1;


    for (int i = 0; i < n; i++){
        minimus = min(minimus, dp[i][k-1]);
    }


    cout << minimus << endl;




    return 0;
}
