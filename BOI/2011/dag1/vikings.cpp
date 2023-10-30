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
 
const int MAXN = 701;
bool arr[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
pair<int, int> treasure;
pair<int, int> vikingStart;
pair<int, int> start;
int n, m;
int howManyRound[MAXN][MAXN];
 
void initHow(){
    queue<pair<pair<int, int>,int> > q;
    q.push({vikingStart, 0});
 
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();
        int i = x;
 
        while (i < n && !arr[i][y]){
            howManyRound[i][y] = min(howManyRound[i][y], w);
            i++;
        }
        i = x-1;
        while (i >= 0 && !arr[i][y]){
            howManyRound[i][y] = min(howManyRound[i][y], w);
            i--;
        }
 
        i = y;
 
        while (i < m && !arr[x][i]){
            howManyRound[x][i] = min(howManyRound[x][i], w);
            i++;
        }
 
        i = y-1;
        while (i >= 0 && !arr[x][i]){
            howManyRound[x][i] = min(howManyRound[x][i], w);
            i--;
        }
 
        if (x > 0 && !isVisited[x-1][y] && !arr[x-1][y]){
            isVisited[x-1][y] = true;
            q.push({{x-1, y}, w+1});
        }
        if (x < n-1 && !isVisited[x+1][y] && !arr[x+1][y]){
            isVisited[x+1][y] = true;
            q.push({{x+1, y}, w+1});
        }
        if (y > 0 && !isVisited[x][y-1] && !arr[x][y-1]){
            isVisited[x][y-1] = true;
            q.push({{x, y-1}, w+1});
        }
        if (y < m-1 && !isVisited[x][y+1] && !arr[x][y+1]){
            isVisited[x][y+1] = true;
            q.push({{x, y+1}, w+1});
        }
    }
    return;
}
 
int main(){
    scoobydoobydoo();
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            howManyRound[i][j] = 2e9;
            arr[i][j] = (c == 'I');
            if (c == 'V')vikingStart = {i, j};
            else if (c == 'Y')start = {i, j};
            else if (c == 'T')treasure = {i, j};
        }
    }
 
    initHow();
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            isVisited[i][j] = false;
        }
    }

 
    queue<pair<pair<int, int>, int> > q;
 
    q.push({start, 0});
 
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();
        if (x == treasure.first && y == treasure.second){
            cout << "YES" << endl;
            return 0;
        }
 
        if (x > 0 && !isVisited[x-1][y] && !arr[x-1][y] && howManyRound[x-1][y] > w+1){
            isVisited[x-1][y] = true;
            q.push({{x-1, y}, w+1});
        }
        if (x < n-1 && !isVisited[x+1][y] && !arr[x+1][y] && howManyRound[x+1][y] > w+1){
            isVisited[x+1][y] = true;
            q.push({{x+1, y}, w+1});
        }
        if (y > 0 && !isVisited[x][y-1] && !arr[x][y-1] && howManyRound[x][y-1] > w+1){
            isVisited[x][y-1] = true;
            q.push({{x, y-1}, w+1});
        }
        if (y < m-1 && !isVisited[x][y+1] && !arr[x][y+1] && howManyRound[x][y+1] > w+1){
            isVisited[x][y+1] = true;
            q.push({{x, y+1}, w+1});
        }
    }
 
    cout << "NO" << endl;
 
    return 0;
}
