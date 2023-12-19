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
#include <deque>
 
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
 
vector<pair<int, int> > neighbours;
 
const int MAXN = 4e3+1;
char arr[MAXN][MAXN];
int isVisited[MAXN][MAXN];
 
int main(){
    scoobydoobydoo();
    int r, C; cin >> r >> C;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }
 
    deque<vector<int> > dq; //x, y, w
    dq.push_back({0, 0, 1});
    int lastW;
 
    while (!dq.empty()){
        int x = dq.front()[0];
        int y = dq.front()[1];
        int w = dq.front()[2];
        dq.pop_front();
        if (isVisited[x][y] != 0 && isVisited[x][y] < w)continue;
    
        lastW = w;      
        char c = arr[x][y];
        if (x > 0 && arr[x-1][y] != '.'){
            if (arr[x-1][y] == c && (isVisited[x-1][y] > w || isVisited[x-1][y] == 0)){
                isVisited[x-1][y] = w;
                dq.push_front({x-1, y, w});
            } else if ((isVisited[x-1][y] > w+1 || isVisited[x-1][y] == 0)){
                isVisited[x-1][y] = w+1;
                dq.push_back({x-1, y, w+1});
            }
        }
        if (x < r-1 && arr[x+1][y] != '.'){
            if (arr[x+1][y] == c && (isVisited[x+1][y] > w || isVisited[x+1][y] == 0)){
                isVisited[x+1][y] = w;
                dq.push_front({x+1, y, w});
            } else if ((isVisited[x+1][y] > w+1 || isVisited[x+1][y] == 0)){
                isVisited[x+1][y] = w+1;
                dq.push_back({x+1, y, w+1});
            }
        }
        if (y > 0 && arr[x][y-1] != '.'){
            if (arr[x][y-1] == c && (isVisited[x][y-1] > w || isVisited[x][y-1] == 0)){
                isVisited[x][y-1] = w;
                dq.push_front({x, y-1, w});
            } else if ((isVisited[x][y-1] > w+1 || isVisited[x][y-1] == 0)){
                isVisited[x][y-1] = w+1;
                dq.push_back({x, y-1, w+1});
            }
        }
        if (y < C-1  && arr[x][y+1] != '.'){
            if (arr[x][y+1] == c && (isVisited[x][y+1] > w || isVisited[x][y+1] == 0)){
                isVisited[x][y+1] = w;
                dq.push_front({x, y+1, w});
            } else if ((isVisited[x][y+1] > w+1 || isVisited[x][y+1] == 0)){
                isVisited[x][y+1] = w+1;
                dq.push_back({x, y+1, w+1});
            }
        }
    }
 
    cout << lastW << endl;
 
    return 0;
}
