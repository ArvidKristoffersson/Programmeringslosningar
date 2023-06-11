#include <iostream>

using namespace std; 

const int MAXN = 501;
char board[MAXN][MAXN];
int n, m;
bool isVisited[MAXN][MAXN], found = false;
char colour = '.';

void floodfill(int r, int c){
    if (r < 0 || r >= n || c < 0 || c >= m || isVisited[r][c] || found)return;
    if (board[r][c] != colour){
        if (board[r][c] != 'H')return;
        found = true;
        return;
    }
    isVisited[r][c] = true;

    floodfill(r-2, c-1);
    floodfill(r-2, c+1);
    floodfill(r-1, c-2);
    floodfill(r-1, c+2);
    floodfill(r+2, c-1);
    floodfill(r+2, c+1);
    floodfill(r+1, c-2);
    floodfill(r+1, c+2);

    //cout << 1 << endl;

    return;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            //cout << 5 << ": " << board[i][j] << endl;
        }
    }

    for (int i = 0; i < n; i++){
        //cout << 7 << endl;
        for (int j = 0; j < m; j++){
            if(board[i][j] == 'H'){
                board[i][j] = '.';
                //cout << 4 << endl;
                floodfill(i, j);
            }
            if (found){
                cout << "JA" << endl;
                return 0;
            }
        }
    }

    cout << "NEJ" << endl;

    return 0;
}
