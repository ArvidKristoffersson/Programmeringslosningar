#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> minCoin(vector<int> coins, int target){
    vector<int> minimus = {0};
    for (int i = 1; i <= target; i++){
        minimus.push_back(2147483647);
        for (int j = 0; j < coins.size(); j++){
            if (i-coins[j] >= 0){
                minimus[i] = min(minimus[i], minimus[i-coins[j]]+1);
            }
        }
    }
    return minimus;
}

int main(){
    int x, y, n; cin >> n;
    double q = (n%100);
    if (q != 0){
        if (n%50 == 0){
            x = n+50;
        } else {
            x = floor(n/100) + ceil(q/100);
            x *= 100;
        }
    } else {
        x = n;
    }

    vector<int> v = minCoin({100, 200, 500}, x);

    cout << v[v.size()-1] << endl;

    return 0;
}
