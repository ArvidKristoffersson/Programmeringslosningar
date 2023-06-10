#include <iostream>
#include <map>
#include <set>

using namespace std; 

const int MAXN = 1e3;
int column[MAXN];
char board[MAXN][MAXN];

int main(){
    map<char, int> m;
    set<int> s;
    int r, c, k; cin >> r >> c >> k;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < c; i++){
        int colour = i+1;
        for (int j = 0; j < r; j++){
            if (m[board[j][i]] > 0){
                colour = m[board[j][i]];
                break;
            }
        }

        for (int j = 0; j < r; j++){
            m[board[j][i]] = colour;
        }
        column[i] = colour;
    }


    for (int i = 0; i < c; i++){
        s.insert(column[i]);
    }


    cout << s.size() << endl;




    return 0;
}
