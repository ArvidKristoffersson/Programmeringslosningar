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

map<vector<ll>, ll> mem;
vector<ll> regering;
ll majoritet;

ll dp(int index, ll accumulatedWealth, ll smallest){
    if (mem.find({index, accumulatedWealth, smallest}) != mem.end()){
        return mem[{index, accumulatedWealth, smallest}];
    }
    if (accumulatedWealth*2 > majoritet && 2*(accumulatedWealth - smallest) <= majoritet){
        return 1;
    } 

    if (index == regering.size() || accumulatedWealth*2 > majoritet){
        return 0;
    } 




    ll best = 0;

    best += dp(index + 1, accumulatedWealth, smallest);
    best += dp(index + 1, accumulatedWealth + regering[index], min(smallest, regering[index]));

    return mem[{index, accumulatedWealth, smallest}] = best;
}

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    ll sum = 0;

    for (int i = 0; i < n; i++){
        int t; cin >> t;
        sum += t;
        regering.push_back(t);
    }
    majoritet = sum;

    cout << dp(0, 0, linf) << endl;


    return 0;
}
