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
 
bool disAllowed[10001][10001];
 
int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        disAllowed[a][b] = true;
        disAllowed[b][a] = true;
    }
 
    ll sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                sum++;
                if (disAllowed[i][j] || disAllowed[j][i]){
                    sum--;
                } else if (disAllowed[i][k] || disAllowed[k][i]){
                    sum--;
                } else if (disAllowed[j][k] || disAllowed[k][j]){
                    sum--;
                }
            }
        }
    }
    
    cout << sum << endl;
 
    return 0;
}
