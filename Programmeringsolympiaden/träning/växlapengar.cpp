#include <iostream>
#include <vector>

using namespace std; 

const int MAXN = 1e3;
int dp[MAXN];

int main(){
    int q; cin >> q;
    vector<int> v = {1, 5, 20};
    q = 100 - q;

    for (int i = 0; i < MAXN; i++){
        dp[i] = 1e7;
    }

    dp[0] = 0;

    for (int i = 1; i <= q+1; i++){
        for (int e : v){
            if (i - e >= 0){
                dp[i] = min(dp[i], dp[i-e]+1);
            }
        }
    }

    cout << dp[q] << endl;
}
