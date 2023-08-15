#include <iostream>
#include <vector>
 
using namespace std; 
 
const int MAXN = 1e6+1;
int minCoins[MAXN];
 
int main(){
    int n, x; cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
 
 
    minCoins[0] = 0;
    for (int i = 1; i <= x; i++){
        minCoins[i] = (int) 1e8;
    }
 
    for (int i = 1; i <= x; i++){
        for (auto e : v){
            if (i-e >= 0){
                minCoins[i] = min(minCoins[i], minCoins[i-e]+1);
            }
        }
    }
 
    if (minCoins[x] == (int) 1e8){
        cout << -1 << endl;
        return 0;
    }
    cout << minCoins[x] << endl;
 
 
 
 
 
    return 0;
}
