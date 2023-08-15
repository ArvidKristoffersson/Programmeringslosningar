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
        ll a, b; cin >> a >> b;
        ll result = 1;
        while (b){
            if (b&1)result = (a*result)%M;
            a = (a*a)%M;
            b = b >> 1;
        }
 
        ans.push_back(result);
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
    return 0;
}
