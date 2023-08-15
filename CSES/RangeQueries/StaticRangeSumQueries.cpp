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
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    vector<ll> pref(n+1);
 
    pref.push_back(0);
 
    for (int i = 1; i <= n; i++){
        cin >> pref[i];
        pref[i] += pref[i-1];
    }
 
    vector<ll> ans;
 
    while (q--){
        int a, b; cin >> a >> b;
        ans.push_back(pref[b]-pref[a-1]);
    }
 
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
    return 0;
}
