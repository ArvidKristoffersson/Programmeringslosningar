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

const int MAXN = 3e2+7;
ll mem[MAXN][MAXN][2]; //index, left, isLeft
vector<ll> coords;
int n;
int orLeft;

ll dp(int index, int left, int isLeft){
    if (left <= 0)return 0;
    if (mem[index][left][isLeft] != 1)return mem[index][left][isLeft];
    if (isLeft){
        return mem[index][left][isLeft] = max((index == 0 ? -linf : dp(index-1, left-1, 1)-left*(coords[index]-coords[index-1])), (index+(orLeft-left+1) >= coords.size() ? -linf : dp(index+(orLeft-left+1), left-1, 0)-left*(coords[index+(orLeft-left+1)]-coords[index]))); 
    }
    return mem[index][left][isLeft] = max((index == coords.size()-1 ? -linf : dp(index+1, left-1, 0)-left*(coords[index+1]-coords[index])), (index-(orLeft-left+1) < 0 ? -linf : dp(index-(orLeft-left+1), left-1, 1)-left*(coords[index]-coords[index-(orLeft-left+1)])));
}

int whereZ;

void clearMem(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= whereZ; j++){
            mem[j][i][1] = 1;
        }
        for (int j = whereZ; j <= n; j++){
            mem[j][i][0] = 1;
        }
    }
}

int main(){
    scoobydoobydoo();
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        coords.push_back(a);
    }
    coords.push_back(0);
    sort(all(coords));
    for (int i = 0; i <= n; i++){
        if (coords[i] == 0)whereZ = i;
    }
    ll maxi = 0;
    for (int i = 1; i <= n; i++){
        clearMem();
        ll best = -linf;
        orLeft = i;
        if (whereZ != 0)best = max(best, dp(whereZ-1, i-1, 1)-i*(coords[whereZ]-coords[whereZ-1]));
        if (whereZ != coords.size()-1)best = max(best, dp(whereZ+1, i-1, 0)-i*(coords[whereZ+1]-coords[whereZ]));
        maxi = max(maxi, best+(i)*m);
    }
    
    cout << maxi << endl;

    return 0;
}
