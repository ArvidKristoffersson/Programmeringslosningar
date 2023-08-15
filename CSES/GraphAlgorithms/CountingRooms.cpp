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
 
char board[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
char colour = '.';
int r, c;
 
 
void floodFill(int x, int y){
    if (x < 0 || y < 0 || x >= r || y >= c || isVisited[x][y] || board[x][y] != colour)return;
    isVisited[x][y] = true;
 
    floodFill(x-1, y);
    floodFill(x+1, y);
    floodFill(x, y-1);
    floodFill(x, y+1);
    return;
}
 
int main(){
    scoobydoobydoo();
 
    cin >> r >> c;
 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }
 
    int ans = 0;
 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (board[i][j] == colour && !isVisited[i][j]){
                ans++;
                floodFill(i, j);
            }
        }
    }
 
    cout << ans << endl;
 
    return 0;
}
