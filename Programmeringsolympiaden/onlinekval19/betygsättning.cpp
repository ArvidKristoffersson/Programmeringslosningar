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

bool isVisited[MAXN][MAXN];
bool isOnFire[MAXN][MAXN];

int main(){
    scoobydoobydoo();
    int n, m;
    long long T;
    cin >> n; cin >> m;
    cin >> T;
    
    if (n == 1 && m == 0){
        cout << 2*(T*T) + 2 * T + 1 << endl;
        return 0;
    }  

    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        isVisited[a+401][b+401] = true;
        isOnFire[a+401][b+401] = true;
        q.push({{a+401, b+401}, 0});
    }

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        isVisited[a+401][b+401] = true;
    }
  
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int tid = q.front().second;
        q.pop();
        if (tid >= T)continue;

        if (x+1 < 1e3+1 && !isVisited[x+1][y]){
            isVisited[x+1][y] = true;
            isOnFire[x+1][y] = true;
            q.push({{x+1, y}, tid+1});
        }
        if (x-1 >= 0 && !isVisited[x-1][y]){
            isVisited[x-1][y] = true;
            isOnFire[x-1][y] = true;
            q.push({{x-1, y}, tid+1});
        }
        if (y+1 < 1e3+1 && !isVisited[x][y+1]){
            isVisited[x][y+1] = true;
            isOnFire[x][y+1] = true;
            q.push({{x, y+1}, tid+1});
        }
        if (y-1 >= 0 && !isVisited[x][y-1]){
            isVisited[x][y-1] = true;
            isOnFire[x][y-1] = true;
            q.push({{x, y-1}, tid+1});
        }
        
    }

    ll sum = 0;
    for (int i = 0; i < 1e3+1; i++){
        for (int j = 0; j < 1e3+1; j++){
            sum += isOnFire[i][j];
        }
    }


    cout << sum << endl;


    return 0;
}
