#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

vector<vector<char>> board;
vector<vector<ll> > isVisited;

vector<vector<int> > generateMoves(int x, int y, int w, ll k, int dir){
    vector<vector<int>> ret;
    for (int i = x+1; i < board.size() && board[i][y] != '#' && i-x <= k && dir != 0 && isVisited[i][y] >= w; i++){
        if (isVisited[i][y] == w)continue;
        ret.push_back({i, y, 1});
        isVisited[i][y] = w;
    }

    for (int i = x-1; i > -1 && board[i][y] != '#' && x-i <= k && dir != 1 && isVisited[i][y] >= w; i--){
        if (isVisited[i][y] == w)continue;
        ret.push_back({i, y, 0, w});
        isVisited[i][y] = w;
    }

    for (int i = y+1; i < board[x].size() && board[x][i] != '#' && i-y <= k && dir != 2 && isVisited[x][i] >= w; i++){
        if (isVisited[x][i] == w)continue;
        ret.push_back({x, i, 3});
        isVisited[x][i] = w;
    }

    for (int i = y-1; i > -1 && board[x][i] != '#' && y-i <= k && dir != 3 && isVisited[x][i] >= w; i--){
        if (isVisited[x][i] == w)continue;
        ret.push_back({x, i, 2});
        isVisited[x][i] = w;
    }


    return ret;
}

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){

    fast();

    ll n, m, k; cin >> n >> m >> k;

    ll u1, u2;

    queue<vector<int> > q;

    for (int i = 0; i < n; i++){
        board.push_back({});
        isVisited.push_back({});
        for (int j = 0; j < m; j++){
            board[i].push_back('.');
            isVisited[i].push_back(1e9+1);
            cin >> board[i][j];
            if (board[i][j] == 'S'){
                q.push({i, j, -1, 0});
                board[i][j] == '.';
                isVisited[i][j] = 0;
            } else if (board[i][j] == 'G'){
                u1 = i;
                u2 = j;
                board[i][j] = '.';
            }
        }
    }


    while (!q.empty()){
        int i = q.front()[0];
        int j = q.front()[1];
        int dir = q.front()[2];

        if (i == u1 && j == u2){
            cout << isVisited[i][j] << endl;
            return 0;
        }
        q.pop();
        vector<vector<int> > v = generateMoves(i, j, isVisited[i][j]+1, k, dir);
        for (auto e : v){
            q.push({e[0], e[1], e[2]});
        }
    }


    cout << isVisited[u1][u2] << endl;

    
    return 0;
}
