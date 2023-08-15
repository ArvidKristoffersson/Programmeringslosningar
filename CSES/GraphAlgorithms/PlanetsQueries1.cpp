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
 
const int MAXN = 2e5+1;
int parent[MAXN], bPar[MAXN][31];
 
int n, q;
 
void initB(){
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < 31; j++){
            bPar[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++){
        bPar[i][0] = parent[i];
    }
 
    for (int l = 1; l < 31; l++){
        for (int i = 0; i < n; i++){
            if (bPar[i][l-1] != -1){
                bPar[i][l] = bPar[bPar[i][l-1]][l-1];
            }
        }
    }
}
  
 
int main(){
    scoobydoobydoo();
    cin >> n >> q;
 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        parent[i] = x;
    }
 
    initB();
 
    vector<int> ans;
 
    while (q--){
        int x, k; cin >> x >> k;
        x--;
        for (int i = 30; i >= 0; i--){
            if(k & (1 << i)){
                x = bPar[x][i];
            }
        }
        ans.push_back(x);
    }
 
    for (auto e : ans){
        cout << e+1 << endl;
    }
 
 
    return 0;
}
