//12 poäng
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

const int MAXN = 1e6+1;

bool arr[MAXN];

int main(){
    scoobydoobydoo();
    int n, m, k; cin >> n >> m >> k;

    if (k != 1){
        cout << -1 << endl;
        return 0;
    } 


    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if (a == n){
            arr[b] = true;
        } else if (b == n){
            arr[a] = true;
        }
    }

    for (int i = 1; i < n; i++){
        if (!arr[i]){
            cout << 1 << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;




    return 0;
}
