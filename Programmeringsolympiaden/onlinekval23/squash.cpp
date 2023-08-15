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

const int MAXN = 1e3+1;
int mem[MAXN][MAXN][2];

string s; 

int dp(int index, int rem, bool isIn){
    if (index == s.size()){
        return 0;
    }
    if (mem[index][rem][isIn] != -1){
        return mem[index][rem][isIn];
    }

    int current = (s[index] == 'V' ? 1 : -1);

    int best = 0;

    if (isIn){
        best = max(best, dp(index+1, rem, false));
        best = max(best, dp(index+1, rem, true) + current);
    } else {
        if (rem > 0) best = max(best, dp(index+1, rem-1, true)+current);
        best = max(best, dp(index+1, rem, false));
    }

    return mem[index][rem][isIn] = best;
}

int main(){
    scoobydoobydoo();
    int n, k; cin >> n >> k;
    cin >> s;
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            mem[i][j][0] = -1;
            mem[i][j][1] = -1;
        }
    }

    cout << dp(0, k, 0) << endl;

    return 0;
}
