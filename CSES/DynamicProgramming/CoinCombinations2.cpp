#include <iostream>
#include <vector>
 
using namespace std; 
 
const int MAXN = 1e6+1;
long long dp[MAXN];
 
int main(){
    int n, x; cin >> n >> x;
    vector<int> v;
    long long q = 1e9+7;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
 
    dp[0] = 1;
 
 
    for (auto e : v){
        for (int i = 1; i <= x; i++){
            if (i-e >= 0){
                dp[i] += dp[i-e];
            }
            dp[i] = dp[i]%q;
        }
    }
 
 
    cout << dp[x] << endl;
 
    return 0;
}
