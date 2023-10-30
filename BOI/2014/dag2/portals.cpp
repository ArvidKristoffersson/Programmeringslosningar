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
 
const int MAXN = 1e3+3;
bool arr[MAXN][MAXN];
int closestWall[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
pair<int, int> portals[MAXN][MAXN][4];
vector<pair<int, int> > walls;
unordered_map<int, queue<pair<int, int> >> portsZ;
 
int main(){
    scoobydoobydoo();
    queue<vector<int>> q;
    pair<int, int> start, ending;
    int r, c; cin >> r >> c;
 
    for (int i = 0; i <= c+1; i++){
        arr[0][i] = false;
        walls.push_back({0, i});
        q.push({0, i, 0});
    }
    
    for (int i = 1; i <= r; i++){
        arr[i][0] = false;
        walls.push_back({i, 0});
        q.push({i, 0, 0});
        isVisited[i][0] = true;
        for (int j = 1; j <= c; j++){
            char l; cin >> l;
            arr[i][j] = (l != '#');
            if (l == '#'){
                q.push({i, j, 0});
                walls.push_back({i, j});
                isVisited[i][j] = true;
            }
            if (l == 'S'){
                start = {i, j};
            }
            if (l == 'C'){
                ending = {i, j};
            }
        }
        arr[i][c+1] = false;
        walls.push_back({i, c+1});
        q.push({i, c+1, 0});
        isVisited[i][c+1] = true;
    }
    for (int i = 0; i <= c+1; i++){
        arr[r+1][i] = false;
        walls.push_back({r+1, i});
        q.push({r+1, i, 0});
    }
 
    while (!q.empty()){
        int i = q.front()[0];
        int j = q.front()[1];
        int w = q.front()[2];
        closestWall[i][j] = w;
        q.pop();
        if (i+1 < r && arr[i+1][j] && !isVisited[i+1][j]){
            q.push({i+1, j, w+1});
            isVisited[i+1][j] = true;
        }
        if (i-1 >= 0 && arr[i-1][j] && !isVisited[i-1][j]){
            q.push({i-1, j, w+1});
            isVisited[i-1][j] = true;
        }
        if (j+1 < c && arr[i][j+1] && !isVisited[i][j+1]){
            q.push({i, j+1, w+1});
            isVisited[i][j+1] = true;
        }
        if (j-1 >= 0 && arr[i][j-1] && !isVisited[i][j-1]){
            q.push({i, j-1, w+1});
            isVisited[i][j-1] = true;
        }
    }
 
    for (int i = 0; i <= r+1; i++){
        for (int j = 0; j <= c+1; j++){
            isVisited[i][j] = false;
        }
    }
 
    for (auto& e : walls){
        int i = e.first-1;
        int j = e.second;
        while (i >= 0 && arr[i][j]){
            portals[i][j][0] = {e.first-1, e.second};
            i--;
        }
        i = e.first+1;
        while (i <= r+1 && arr[i][j]){
            portals[i][j][1] = {e.first+1, e.second};
            i++;
        }
        i = e.first;
        j = e.second-1;
        while (j >= 0 && arr[i][j]){
            portals[i][j][2] = {e.first, e.second-1};
            j--;
        }
        j = e.second+1;
        while (j <= c+1 && arr[i][j]){
            portals[i][j][3] = {e.first, e.second+1};
            j++;
        }
    }
 
    queue<vector<int> > pq;
    pq.push({0, start.first, start.second});

    while (!pq.empty()){
        int x = pq.front()[1];
        int y = pq.front()[2];
        int w = -pq.front()[0];
        pq.pop();
        if (x == ending.first && y == ending.second){
            cout << w << endl;
            return 0;
        }
        int closest = closestWall[x][y];
        if (arr[x+1][y] && !isVisited[x+1][y]){
            pq.push({-(w+1), x+1, y});
            isVisited[x+1][y] = true;
        }
        if (arr[x-1][y] && !isVisited[x-1][y]){
            pq.push({-(w+1), x-1, y});
            isVisited[x-1][y] = true;
        }
        if (arr[x][y+1] && !isVisited[x][y+1]){
            pq.push({-(w+1), x, y+1});
            isVisited[x][y+1] = true;
        }
        if (arr[x][y-1] && !isVisited[x][y-1]){
            pq.push({-(w+1), x, y-1});
            isVisited[x][y-1] = true;
        }
 
        for (int i = 0; i < 4; i++){
            pair<int, int> e = portals[x][y][i];
            if (!isVisited[e.first][e.second]){
                portsZ[w+closest].push({e.first, e.second});
            }
        }
 
        while (!portsZ[w+1].empty()){
            int x1 = portsZ[w+1].front().first;
            int y1 = portsZ[w+1].front().second;
            portsZ[w+1].pop();
            if (!arr[x1][y1])continue;
            if (!isVisited[x1][y1]){
                isVisited[x1][y1] = true;
                pq.push({-(w+1), x1, y1});
            }
            
        }
        
    }
    
 
    
    return 0;
}
