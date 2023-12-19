#include <iostream>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
 
#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
 
using namespace std;
 
typedef long long ll;
 
ll linf = 1e15+1;
 
inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
const int MAXN = 1e6+1;
 
int counter[MAXN];
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        counter[t]++;
    }
    int ans = 1;
    for (int i = 2; i < MAXN; i++){
        int sum = 0;
        for (int j = i; j < MAXN; j += i){
            sum += counter[j];
        }
        if (sum >= 2)ans = i;
    }
 
    cout << ans << endl;
 
    return 0;
}
