#include <iostream>
 
using namespace std; 
 
const int MAXN = 1e3 + 1;
long long dp[MAXN][MAXN];
char board[MAXN][MAXN];
 
int main(){ 
    int n; cin >> n;
 
    long long q = 1e9+7;
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
 
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (board[i][j] == '.'){
                if (i != 0){
                    dp[i][j] += dp[i-1][j];
                }
                if (j != 0){
                    dp[i][j] += dp[i][j-1];
                }
                dp[i][j] = dp[i][j]%q;
            } else {
                dp[i][j] = 0;
            }
        } 
    }

 
   cout << dp[n-1][n-1] << endl;
 
 
 
    return 0;
}
