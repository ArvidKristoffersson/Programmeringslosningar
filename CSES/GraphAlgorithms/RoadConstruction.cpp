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
 
const int MAXN = 2e5+1;
int parent[MAXN], sill[MAXN];
 
int biggestComp = 1;
 
int rootOf(int x){
    return (x == parent[x] ? x : parent[x] = rootOf(parent[x]));
}
 
bool unite(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (a == b)return false;
    if (sill[a] < sill[b])swap(a, b);
    parent[b] = a;
    sill[a] += sill[b];
    biggestComp = max(biggestComp, sill[a]);
    return true;
}
 
int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++){
        parent[i] = i;
        sill[i] = 1;
    }
    vector<pair<int, int > > ans;
    int c = n;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if (unite(x, y)){
            c--;
        }
        ans.push_back({c, biggestComp});
    }
 
    for (auto e : ans){
        cout << e.first << " " << e.second << endl;
    }
 
 
    return 0;
}
