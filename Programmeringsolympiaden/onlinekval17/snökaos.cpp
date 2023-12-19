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

const int MAXN = 2e2+1;
vector<int> endsHere[MAXN];
bool impossible[MAXN];
int n, m, s, p; 

ll mem[MAXN][MAXN][MAXN]; 

ll dp(int leftmost, int index, int plow){
    if (index == n)return 0;
    if (mem[leftmost][index][plow] != -1)return mem[leftmost][index][plow];

    ll best = -1;
    ll extra = 0;
    for (auto& e : endsHere[index]){
        if (e >= leftmost)extra++;
    }
    if (impossible[index]){
        if (plow > 0)best = max(best, dp(leftmost, index+1, plow-1)+extra);
        best = max(best, dp(index+1, index+1, plow)+extra);
    } else {
        best = max(best, dp(leftmost, index+1, plow)+extra);
    }
    return mem[leftmost][index][plow] = best;
}

int main(){
    scoobydoobydoo();
    cin >> n >> m >> s >> p;

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--; 
        endsHere[max(a, b)].push_back(min(a, b));
    }

    for (int i = 0; i < s; i++){
        int x; cin >> x;
        impossible[--x] = true;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k <= p; k++)mem[i][j][k] = -1;
        }
    }

    cout << dp(0, 0, p) << endl;

    return 0;
}
