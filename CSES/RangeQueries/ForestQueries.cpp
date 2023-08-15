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
 
const int MAXN  = 1e3+1;
int arr[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
int n;
 
int recursion(int x, int y){
    if (x == n || y == n)return 0;
    if (isVisited[x][y])return arr[x][y];
 
    isVisited[x][y] = true;
    return arr[x][y] += recursion(x+1, y) + recursion(x, y+1) - recursion(x+1, y+1);
}
 
int main(){
    scoobydoobydoo();
    int Q; cin >> n >> Q;
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c; cin >> c;
            arr[i][j] = (c == '*');
        }
    }
 
    vector<ll> ans;
 
    recursion(0, 0);
 
 
    while (Q--){
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        ans.push_back(arr[x1-1][y1-1] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x2][y2]);
    }
 
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
 
 
    return 0;
}
