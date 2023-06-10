#include <iostream>
#include <vector>

using namespace std; 

const int MAXM = 1e4+1;

int main(){
    int m, n; cin >> m >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int tI; cin >> tI;
        nums.push_back(tI);
    }
    int dp[MAXM];
    dp[0] = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            int q = nums[j];
            if (i-q > -1)dp[i] += dp[i-q];
        }
    }

    cout << dp[m] << endl;


    return 0;
}
