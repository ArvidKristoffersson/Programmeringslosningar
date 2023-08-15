#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
 
#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
 
typedef long long ll;
 
ll linf = 1e15+1;
 
using namespace std;
 
inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
const int MAXN = 2e5+3;
 
int parent[MAXN], binPar[MAXN][30];
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < n; j++){
            binPar[j][i] = -1;
        }
    }
    
    parent[0] = -1;
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        parent[i] = x;
        binPar[i][0] = x;
    }
 
    for (int i = 1; i < 30; i++){
        for (int j = 0; j < n; j++){
            if (binPar[j][i-1] != -1){
                binPar[j][i] = binPar[binPar[j][i-1]][i-1];
            }
        }
    }
 
    vector<int> v;
 
    while (q--){
        int x, k; cin >> x >> k;
        x--;
        int last = x;
        for (int i = 0; i < 30; i++){
            if (last == -1)continue;
            if (k&(1<<i)){
                last = binPar[last][i];
            }
        }
        v.push_back(last);
    }
 
    for (auto e : v){
        cout << (e == -1 ? -1 : e+1) << endl;
    }
 
 
    return 0;
}
