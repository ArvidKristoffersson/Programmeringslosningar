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

bool isVisited[101][101][201];
char board[101][101];

int main(){
    scoobydoobydoo();
    int r, c, k; cin >> r >> c >> k;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }

    queue<vector<int>> q;
    q.push({0, 0, k, 0});

    while (!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int rest = q.front()[2];
        int steps = q.front()[3];
        q.pop();
        if (x == r-1 && y == c-1){
            cout << steps << endl;
            return 0;
        }
        if (x - 1 >= 0){
            if (board[x-1][y] == '#'){
                if (!isVisited[x-1][y][rest-1] && rest > 0){
                    isVisited[x-1][y][rest-1] = true;
                    q.push({x-1, y, rest-1, steps+1});
                }
            } else if (!isVisited[x-1][y][rest]){
                isVisited[x-1][y][rest] = true;
                q.push({x-1, y, rest, steps+1});
            }
        }
        if (x + 1 < r){
            if (board[x+1][y] == '#'){
                if (!isVisited[x+1][y][rest-1] && rest > 0){
                    isVisited[x+1][y][rest-1] = true;
                    q.push({x+1, y, rest-1, steps+1});
                }
            } else if (!isVisited[x+1][y][rest]){
                isVisited[x+1][y][rest] = true;
                q.push({x+1, y, rest, steps+1});
            }
        }
        if (y - 1 >= 0){
            if (board[x][y-1] == '#'){
                if (!isVisited[x][y-1][rest-1] && rest > 0){
                    isVisited[x][y-1][rest-1] = true;
                    q.push({x, y-1, rest-1, steps+1});
                }
            } else if (!isVisited[x][y-1][rest]){
                isVisited[x][y-1][rest] = true;
                q.push({x, y-1, rest, steps+1});
            }
        }
        if (y + 1 < c){
            if (board[x][y+1] == '#'){
                if (!isVisited[x][y+1][rest-1] && rest > 0){
                    isVisited[x][y+1][rest-1] = true;
                    q.push({x, y+1, rest-1, steps+1});
                }
            } else if (!isVisited[x][y+1][rest]){
                isVisited[x][y+1][rest] = true;
                q.push({x, y+1, rest, steps+1});
            }
        }
    }

    cout << "nej" << endl;


    return 0;
}
