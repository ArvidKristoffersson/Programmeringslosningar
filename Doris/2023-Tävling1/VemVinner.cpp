#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <unordered_map>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

char board[3][3];

int calcRow(){
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            if (board[i][0] == 'X'){
                return 1;
            } else if (board[i][0] == 'O'){
                return -1;
            }
        }
    }
    return 0;
}

int calcCol(){
    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if (board[0][i] == 'X'){
                return 1;
            } else if (board[0][i] == 'O'){
                return -1;
            }
        }
    }
    return 0;
}

int calcDiag(){
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if (board[0][0] == 'X'){
            return 1;
        } else if (board[0][0] == 'O'){
            return -1;
        }
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        if (board[2][0] == 'X'){
            return 1;
        } else if (board[2][0] == 'O'){
            return -1;
        }
    }
    return 0;
}

int main(){
    scoobydoobydoo();
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> board[i][j];
        }
    }
    
    int rS = calcRow();
    int rC = calcCol();
    int rD = calcDiag();
    
    if (rS != 0){
        if (rS == 1){
            cout << "Johan har vunnit" << endl;
        } else {
            cout << "Abdullah har vunnit" << endl;
        }
        return 0;
    }
    if (rC != 0){
        if (rC == 1){
            cout << "Johan har vunnit" << endl;
        } else {
            cout << "Abdullah har vunnit" << endl;
        }
        return 0;
    }
    if (rD != 0){
        if (rD == 1){
            cout << "Johan har vunnit" << endl;
        } else {
            cout << "Abdullah har vunnit" << endl;
        }
        return 0;
    }
    
    cout << "ingen har vunnit" << endl;
    

    return 0;
}
