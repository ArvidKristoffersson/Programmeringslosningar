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
 
 
ll M = 1e9+7;
 
int main(){
    scoobydoobydoo();
    int q; cin >> q;
 
    vector<ll> ans;
 
    while (q--){
        ll a, b, c; cin >> a >> b >> c;
        ll result1 = 1, result2 = 1;
        while (c){
            if (c&1)result1 = (b*result1)%(M-1);
            b = (b*b)%(M-1);
            c = c >> 1;
        }
 
 
        while (result1){
            if (result1&1)result2 = (a*result2)%M;
            a = (a*a)%M;
            result1 = result1 >> 1;
        }
 
        ans.push_back(result2);
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
    return 0;
}
