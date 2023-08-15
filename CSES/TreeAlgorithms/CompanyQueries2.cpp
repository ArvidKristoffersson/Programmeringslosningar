#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
 
#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
 
typedef long long ll;
 
ll linf = 1e15+1;
 
using namespace std;
 
inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
const int MAXN = 2e5+3;
 
int parent[MAXN], binPar[MAXN][30];
vector<int> children[MAXN];
pair<int, int> eulerT[MAXN];
 
int counter = 0;
void eulerTour(int node){
    eulerT[node] = {counter++, -1};
    for (auto e : children[node]){
        eulerTour(e);
    }
    eulerT[node] = {eulerT[node].first, counter++};
    return;
}
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < n; j++){
            binPar[j][i] = -1;
        }
    }
    
    parent[0] = -1;
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        parent[i] = x;
        children[x].push_back(i);
        binPar[i][0] = x;
    }
 
    for (int i = 1; i < 30; i++){
        for (int j = 0; j < n; j++){
            if (binPar[j][i-1] != -1){
                binPar[j][i] = binPar[binPar[j][i-1]][i-1];
            }
        }
    }
 
    eulerTour(0);
 
    vector<int> v;

    while (q--){
        int x, y; cin >> x >> y;
        int ans = -1;
        x--; y--;
 
        if (x == y){
            v.push_back(x);
            continue;
        }
 
        if (eulerT[x].first < (eulerT[y].first) && eulerT[x].second > eulerT[y].second){
            v.push_back(x);
            continue;
        } else if (eulerT[x].first > (eulerT[y].first) && eulerT[x].second < eulerT[y].second){
            v.push_back(y);
            continue;
        }
 
        for (int i = 25; i >= 0; i--){
            if (binPar[x][i] == -1)continue;
            int aT = binPar[x][i];
            if (!(eulerT[aT].first < (eulerT[y].first) && eulerT[aT].second > eulerT[y].second)){
                x = aT;
            } else {
                ans = aT;
            }
 
        }
        v.push_back(ans);
        
    }
 
    for (auto e : v){
        cout << (e == -1 ? -1 : e+1) << endl;
    }
 
 
    return 0;
}
