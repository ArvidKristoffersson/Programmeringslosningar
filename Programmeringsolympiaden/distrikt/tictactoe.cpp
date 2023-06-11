#include <iostream>
#include <string>

using namespace std; 

int evaluation(int board[3][3]){
    bool completelyDone = true;
    bool bWon = true, wWon = true, b1Won = true, w1Won = true, done = false;
    for (int i = 0; i < 3 && !done; i++){
        if (!done){
            bWon = true, wWon = true, b1Won = true, w1Won = true;
            for (int j = 0; j < 3; j++){
                if (board[i][j] != -1){
                    bWon = false;
                }
                if (board[i][j] != 1){
                    wWon = false;
                }
                if (board[j][i] != -1){
                    b1Won = false;
                }
                if (board[j][i] != 1){
                    w1Won = false;
                }
                if (board[i][j] == 0){
                    completelyDone = false;
                }
            }
            if (bWon || wWon || b1Won || w1Won){
                done = true;
            }
        }
    }

    bool b2Won = true, w2Won = true, b3Won = true, w3Won = true;

    for (int i = 0; i < 3; i++){
        if (board[i][i] != 1){
            w2Won = false;
        }
        if (board[i][i] != -1){
            b2Won = false;
        }
    }

    for (int i = 2; i > -1; i--){
        int j = abs(i-2);
        if (board[i][j] != 1){
            w3Won = false;
        }
        if (board[i][j] != -1){
            b3Won = false;
        }
    }

    if (b3Won || b2Won || b1Won || bWon)return -1;
    if (w3Won || w2Won || w1Won || wWon)return 1;
    if (!completelyDone)return 3;
    return 0;
}

int minimax(int board[3][3], bool isMax, int depth){
    int score = evaluation(board);
    if (score == -1 || score == 1 || score == 0)return score;

    if (isMax){
        int best = -10;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    board[i][j] = 1;
                    best = max(best, minimax(board, !isMax, depth+1));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    } else {
        int best = 10;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    board[i][j] = -1;
                    best = min(best, minimax(board, !isMax, depth+1));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}


pair<int, int> bestMove(int board[3][3], int colour){
    int bestVal;
    int r = -1, c = -1;

    if (colour == 1){
        bestVal = -1000;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    board[i][j] = colour;
                    int eval = minimax(board, false, 1);
                    board[i][j] = 0;
                    if (eval > bestVal){
                        r = i; 
                        c = j;
                        bestVal = eval;
                    }
                }
            }
        }
    } else {
        bestVal = 1000;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    board[i][j] = colour;
                    int eval = minimax(board, true, 1);
                    board[i][j] = 0;
                    if (eval < bestVal){
                        r = i; 
                        c = j;
                        bestVal = eval;
                    }
                }
            }
        }
    }

    return {r, c};


}

void printArr(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i][j] == 0){
                cout << '.';
            } else if (arr[i][j] == 1){
                cout << 'x';
            } else {
                cout << 'o';
            }
        }
        cout << endl;
    }
    return;
}




int main(){
    int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    bool cool = true;
    string str; cin >> str;
    pair<int, int> p;

    while (cool){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                char t; cin >> t;
                if (t == 'x'){
                    arr[i][j] = 1;
                } else if (t == '.'){
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = -1;
                }
            }
        }
        p = bestMove(arr, 1);
        arr[p.first][p.second] = 1;
        printArr(arr);
        if (evaluation(arr) != 3){
            cool = false;
        }
    }


    return 0;
}
