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
 
const int MAXN = 1e7+1;
 
pair<int, int> dp[MAXN];
int distFrom[MAXN];
int biggestPrime;
 
 
void initDistFrom(int latestW){
    for (int i = 1; i < biggestPrime; i++){
        distFrom[i] = 1;
    }
 
    for (int i = biggestPrime; i <= MAXN; i++){
        if (dp[i].second == 0){
            distFrom[i] = 0;
            continue;
        }
        distFrom[i] = (distFrom[i-i%dp[i].second] == 0 ? 0 : distFrom[i-i%dp[i].second]+1);
    }
}
 
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    vector<int> primez(n);
    for (int i = 0; i < n; i++){
        cin >> primez[i];
    }
 
    biggestPrime = primez[n-1];
 
    int latest = -1;
    int latestW = -1;
 
    for (int e : primez){
        int worth = ((int)1e7)%e;
        if (worth >= latestW){
            latestW = worth;
            latest = e;
        }
    }
 
 
    vector<int> ans;
 
    for (int i = n-1; i >= 0; i--){
        for (int e = primez[i]-1; e <= MAXN; e += primez[i]){
            if (!dp[e].first){
                dp[e] = {primez[i]-1, primez[i]};
            }
        }
    }
 
    
    for (int i = MAXN; i >= 0; i--){
        if (dp[i].first){
            if (i%latest > dp[i].first){
                dp[i].first = i%latest;
                dp[i].second = latest;
            } else {
                latest = dp[i].second;
            }
        } else {
            dp[i] = {i%latest, latest};
        }
    }
 
    initDistFrom(latestW);
 
    while (q--){
        int x; cin >> x;
        if (distFrom[x] == 0)ans.push_back(-1);
        else ans.push_back(distFrom[x]);
    }
 
    for (auto& e : ans){
        if (e == -1)cout << "oo" << endl;
        else cout << e << endl;
    }
 
 
    return 0;
}
