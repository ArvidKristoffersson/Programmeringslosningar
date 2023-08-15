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
 
vector<ll> numPerDiv(int a){
    int b = 2;
    vector<ll> ret;
    while (a != 1){
        if (a%b == 0)ret.push_back(0);
        while (a%b == 0){
            ret[ret.size()-1]++;
            a /= b;
        }
        if (b==2)b--;
        b += 2;
 
        if (b > sqrt(a) && a != 1){
            ret.push_back(1);
            return ret;
        }
    }
    return ret;
}
 
int main(){
    scoobydoobydoo();
    int q; cin >> q;
    vector<ll> ans;
    while (q--){
        int a; cin >> a;
        vector<ll> v = numPerDiv(a);
        ll sum = 1;
        for (auto& e : v){
            sum *= (e+1);
        }
        ans.push_back(sum);
    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
 
    return 0;
}
