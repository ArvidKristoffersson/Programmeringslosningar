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
char prel[MAXN][MAXN];
 
 
int main(){
    scoobydoobydoo();
    int r, c; cin >> r >> c;
    int ax, ay, bx, by;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
            if (board[i][j] == 'A'){
                ax = i; ay = j;
            } else if (board[i][j] == 'B'){
                bx = i; by = j;
            }
        }
    }
 
    queue<pair<int, int> > q;
    q.push({ax, ay});
    isVisited[ax][ay] = true;
 
 
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if (x > 0 && board[x-1][y] != '#' && !isVisited[x-1][y]){
            isVisited[x-1][y] = true;
            q.push({x-1, y});
            prel[x-1][y] = 'U';
        }
        if (x < r-1 && board[x+1][y] != '#' && !isVisited[x+1][y]){
            isVisited[x+1][y] = true;
            q.push({x+1, y});
            prel[x+1][y] = 'D';
        }
        if (y > 0 && board[x][y-1] != '#' && !isVisited[x][y-1]){
            isVisited[x][y-1] = true;
            q.push({x, y-1});
            prel[x][y-1] = 'L';
        }
        if (y < c-1 && board[x][y+1] != '#' && !isVisited[x][y+1]){
            isVisited[x][y+1] = true;
            q.push({x, y+1});
            prel[x][y+1] = 'R';
        }
    }
 
    if (prel[bx][by]){
        cout << "YES" << endl;
        vector<char> v;
        ll x = bx, y = by;
 
        while (true){
            if(!prel[x][y])break;
            char c = prel[x][y];
            if (c == 'R'){
                y--;
            } else if (c == 'L'){
                y++;
            } else if (c == 'U'){
                x++; 
            } else {
                x--;
            }
            v.push_back(c);
        }
        reverse(all(v));
        cout << v.size() << endl;
        for (auto e : v){
            cout << e;
        }
        cout << endl;
        return 0;
    }
 
    cout << "NO" << endl;
 
 
 
    return 0;
}
