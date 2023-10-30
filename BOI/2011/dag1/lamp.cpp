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
 
const int MAXN = 501;
bool start[MAXN][MAXN];
bool isVisited[MAXN][MAXN][2];
 
int main(){
    scoobydoobydoo();
 
    priority_queue<vector<int> > pq;
    //w, r, c, is '/' 
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            start[i][j] = (c == '/');
        }
    }
 
    if (start[0][0]){
        pq.push({-1, 0, 0, 0, -1, -1});
    } else {
        pq.push({0, 0, 0, 0, -1, -1});
    }
 
    while (!pq.empty()){
        int w = -pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        int flip = pq.top()[3];
        int parentC = pq.top()[4];
        int parentR = pq.top()[5];
        pq.pop();
        if (isVisited[r][c][flip]){
            continue;
        }
        isVisited[r][c][flip] = true;
        if (r == n-1 && c == m-1 && flip == 0){
            cout << w << endl;
            return 0;
        }
        if (flip){
            //Uppe
            //Över
            if (r > 0 && !isVisited[r-1][c][0] && (r-1 != parentR || c != parentC)){
                if (start[r-1][c]){
                    pq.push({-(w+1), r-1, c, 0, r, c});
                } else {
                    pq.push({-w, r-1, c, 0, r, c});
                }
            }
            //ÖVER-HÖGER
            if (r > 0 && c < m-1 && !isVisited[r-1][c+1][1] && (r-1 != parentR || c+1 != parentC)){
                if (start[r-1][c+1]){
                    pq.push({-w, r-1, c+1, 1, r, c});
                } else {
                    pq.push({-(w+1), r-1, c+1, 1, r, c});
                }
            }
            //HÖGER
            if (c < m-1 && !isVisited[r][c+1][0] && (r != parentR || c+1 != parentC)){
                if (start[r][c+1]){
                    pq.push({-(w+1), r, c+1, 0, r, c});
                } else {
                    pq.push({-w, r, c+1, 0, r, c});
                }
            }
 
            //NERE
            if (r < n-1 && !isVisited[r+1][c][0] && (r+1 != parentR || c != parentC)){
                if (start[r+1][c]){
                    pq.push({-(w+1), r+1, c, 0, r, c});
                } else {
                    pq.push({-w, r+1, c, 0, r, c});
                }
            }
            //NERE VÄNSTER
            if (r < n-1 && c > 0 && !isVisited[r+1][c-1][1] && (r+1 != parentR || c-1 != parentC)){
                if (start[r+1][c-1]){
                    pq.push({-w, r+1, c-1, 1, r, c});
                } else {
                    pq.push({-(w+1), r+1, c-1, 1, r, c});
                }
            }
 
            if (c > 0 && !isVisited[r][c-1][0] && (r != parentR || c-1 != parentC)){
                if (start[r][c-1]){
                    pq.push({-(w+1), r, c-1, 0, r, c});
                } else {
                    pq.push({-w, r, c-1, 0, r, c});
                }
            }
 
        } else {
            if (r > 0 && !isVisited[r-1][c][1] && (r-1 != parentR || c != parentC)){
                if (start[r-1][c]){
                    pq.push({-w, r-1, c, 1, r, c});
                } else {
                    pq.push({-(w+1), r-1, c, 1, r, c});
                }
            }
            //ÖVER-VÄNSTER
            if (r > 0 && c > 0 && !isVisited[r-1][c-1][0] && (r-1 != parentR || c-1 != parentC)){
                if (start[r-1][c-1]){
                    pq.push({-(w+1), r-1, c-1, 0, r, c});
                } else {
                    pq.push({-w, r-1, c-1, 0, r, c});
                }
            }
            //VÄNSTER
            if (c > 0 && !isVisited[r][c-1][1] && (r != parentR || c-1 != parentC)){
                if (start[r][c-1]){
                    pq.push({-w, r, c-1, 1, r, c});
                } else {
                    pq.push({-(w+1), r, c-1, 1, r, c});
                }
            }
 
            //NERE
            if (r < n-1 && !isVisited[r+1][c][1] && (r+1 != parentR || c != parentC)){
                if (start[r+1][c]){
                    pq.push({-w, r+1, c, 1, r, c});
                } else {
                    pq.push({-(w+1), r+1, c, 1, r, c});
                }
            }
            //NERE HÖGER
            if (r < n-1 && c < m-1 && !isVisited[r+1][c+1][0] && (r+1 != parentR || c+1 != parentC)){
                if (start[r+1][c+1]){
                    pq.push({-(w+1), r+1, c+1, 0, r, c});
                } else {
                    pq.push({-w, r+1, c+1, 0, r, c});
                }
            }
 
            if (c < m-1 && !isVisited[r][c+1][1] && (r != parentR || c+1 != parentC)){
                if (start[r][c+1]){
                    pq.push({-w, r, c+1, 1, r, c});
                } else {
                    pq.push({-(w+1), r, c+1, 1, r, c});
                }
            }
 
        }
    }
 
    cout << "NO SOLUTION" << endl;
 
    return 0;
}
