#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 1e3+1;
int godis[MAXN][11];
bool isPositif[MAXN][11];

int main(){
    scoobydoobydoo();
    int n; cin >> n;

    int best = 0;

    for (int i = 0; i < n; i++){
        int m; cin >> m;
        for (int j = 0; j < m; j++){
            int a, b; cin >> a >> b;
            isPositif[i][abs(a)-1] = (a > 0);
            godis[i][abs(a)-1] = b;
        }
    }
    
    for (int x = 0; x < (1<<10); x++){
        int better = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = 0; j < 10; j++){
                if ((isPositif[i][j] && (x&(1<<j))) || (!isPositif[i][j] && !(x&(1<<j)))){
                    sum += godis[i][j];
                } else {
                    sum -= godis[i][j];
                }
            }
            better += max(0, sum);
        }
        best = max(best, better);
    }

    cout << best << endl;

    return 0;
}
