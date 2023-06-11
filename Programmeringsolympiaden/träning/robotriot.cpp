#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1001;
char board[MAXN][MAXN];
bool isVisited[MAXN][MAXN];

int main(){
    int n, m; cin >> n >> m;
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 'X'){
                q.push({i, j});
            }
        }
    }


    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        isVisited[r][c] = true;
        if (r == n-1 || r == 0 || c == m-1 || c == 0){
            cout << "Death to humans" << endl;
            return 0;
        }
        if (r > 0 && !isVisited[r-1][c] && board[r-1][c] != '#'){
            q.push({r-1, c});
        }
        if (r < n-1 && !isVisited[r+1][c] && board[r+1][c] != '#'){
            q.push({r+1, c});
        }
        if (c > 0 && !isVisited[r][c-1] && board[r][c-1] != '#'){
            q.push({r, c-1});
        }
        if (c < m-1 && !isVisited[r][c+1] && board[r][c+1] != '#'){
            q.push({r, c+1});
        }
    }

    cout << "We are safe" << endl;



    return 0;
}
