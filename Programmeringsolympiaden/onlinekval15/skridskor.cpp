#include <iostream>
#include <queue>
#include <map>

using namespace std; 
const int MAXN = 101;
int r1, c1;
char board[MAXN][MAXN];

pair<int, int> down(int r, int c){
    for(int i = r; i < r1; i++){
        if (board[i][c] == '#'){
            return {i-1, c};
        }
    }
    return {(r1-1), c};
}
pair<int, int> up(int r, int c){
    for(int i = r; i > -1; i--){
        if (board[i][c] == '#'){
            return {i+1, c};
        }
    }
    return {r, c};
}
pair<int, int> left(int r, int c){
    for(int i = c; i > -1; i--){
        if (board[r][i] == '#'){
            return {r, i+1};
        }
    }
    return {r, c};
}
pair<int, int> right(int r, int c){
    for(int i = c; i < c1; i++){
        if (board[r][i] == '#'){
            return {r, i-1};
        }
    }
    return {r, c1};
}

int main(){
    int r, c; cin >> r1 >> c1;
    r = r1; c = c1;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }

    map<pair<int, int>, int> m;
    map<pair<pair<int, int>, bool>, int> u; 
    u[{{0, 0}, true}] = 0;

    queue<pair<pair<pair<int, int>, bool >, pair<int, int> > > q;
    m[{0, 0}] = -1;
    q.push({{right(0, 0), false}, {0, 0}});
    while(!q.empty()){
        int r = q.front().first.first.first, c = q.front().first.first.second;
        bool cool = q.front().first.second;
        pair<int, int> p = q.front().second;
        q.pop();
        if (c == c1){
            cout << u[{p, !cool}] << endl;
            return 0;
        }

        if (u.find({{r, c}, cool}) == u.end()){
            if (cool){
                q.push({{right(r, c), false}, {r, c}});
                q.push({{left(r, c), false}, {r, c}});
            } else {
                q.push({{up(r, c), true}, {r, c}});
                q.push({{down(r, c), true}, {r, c}});
            }
            u[{{r, c}, cool}] = u[{p, !cool}]+1;
        }

    }



    return 0;
}
