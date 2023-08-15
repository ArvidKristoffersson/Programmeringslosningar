#include <iostream>
#include <vector>
 
using namespace std; 
 
const int MAXN = 1e6+1;
long long int ways[MAXN];
 
int main(){
    int n; cin >> n;
    vector<int> v = {1, 2, 3, 4, 5, 6};
 
 
    ways[0] = 1;
 
    long long q = 1e9 + 7;
 
    for (long long i = 1; i <= n; i++){
        for (auto e : v){
            if (i - e >= 0){
                ways[i] += ways[i-e];
                ways[i] = ways[i]%q;
            }
        }
    }
 
 
    cout << ways[n] << endl;
 
 
    return 0;
}
