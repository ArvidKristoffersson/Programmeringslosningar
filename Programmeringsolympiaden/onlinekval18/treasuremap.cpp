#include <iostream>

using namespace std; 

bool isVisited[101][101];
char board[101][101];

void recursion(int r, int c){
    if (isVisited[r][c]){
        cout << "cykel" << endl;
        return;
    } 
    isVisited[r][c] = true;
    char x = board[r][c];
    switch(x){
        case 'A':
            cout << "sushi" << endl;
            return;
        case 'B':
            cout << "samuraj" << endl;
            return;
        case '<':
            recursion(r, c-1);
            break;
        case 'v':
            recursion(r+1, c);
            break;
        case '>':
            recursion(r, c+1);
            break;
        case '^':
            recursion(r-1, c);
            break;
    }

    return;
}

int main(){
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }

    recursion(0, 0);

    return 0;
}
