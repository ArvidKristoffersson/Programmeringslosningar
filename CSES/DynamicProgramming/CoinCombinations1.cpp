#include <iostream>
#include <vector>
 
using namespace std; 
 
const int MAXN = 1e6+1;
long long dist[MAXN];
 
int main(){
    int n, x; cin >> n >> x;
 
    long long q = 1e9 + 7;
 
    vector<int> coins;
 
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        coins.push_back(t);
    }
 
 
    dist[0] = 1;
 
    for (int i = 1; i <= x; i++){
        for (auto e : coins){
            if (i-e >= 0){
                dist[i] += dist[i-e];
            }
        }
        dist[i] = dist[i]%q;
    } 
 
    cout << dist[x] << endl;
 
 
    return 0;
}
