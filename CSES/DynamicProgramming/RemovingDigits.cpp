#include <iostream>
 
using namespace std; 
 
const int MAXN = 1e6+1;
long long dp[MAXN];
 
int main(){
    int n; cin >> n;
    for (int i = 0; i < n+1; i++){
        dp[i] = (long long) 1e9;
    }
    dp[0] = 0;
    for (int i = 1; i < 10; i++){
        dp[i] = 1;
    }
 
 
 
    for (int i = 10; i <= n; i++){
        int q = i;
        while (q > 0){
            dp[i] = min(dp[i], dp[i-q%10]+1);
            q /= 10;
        }
    }
 
    cout << dp[n] << endl;
 
 
 
    return 0;
}
