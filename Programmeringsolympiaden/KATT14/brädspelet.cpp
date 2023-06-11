#include <iostream>

using namespace std; 

int dp[101][101];

int dyn(int r, int c){
    if (r == 1 && c == 1)return 0;
    if (dp[r][c] > -1)return dp[r][c];

    bool won = false;

    for (int i = 1; i < r && !won; i++){
        won = !dyn(r - i, c) && !dyn(i, c);
    }
    for (int i = 1; i < c && !won; i++){
        won = !dyn(r, c - i) && !dyn(r, i);
    }

    return dp[r][c] = won;
}

int main(){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            dp[i][j] = -1;
        }
    }
    int r, c; cin >> r >> c;

    if (dyn(r, c))cout << 'A' << endl;
    else cout << 'B' << endl;


    return 0;
}
