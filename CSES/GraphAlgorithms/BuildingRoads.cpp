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
 
const int MAXN = 2e5+1;
int parent[MAXN], sill[MAXN];
 
int rootOf(int x){
    return (x == parent[x] ? x : parent[x] = rootOf(parent[x]));
}
 
bool unite(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (a == b)return false;
    if (sill[a] < sill[b])swap(a, b);
    sill[a] += sill[b];
    parent[b] = a;
    return true;
}
 
int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++){
        parent[i] = i;
        sill[i] = 1;
    }
 
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        unite(x, y);
    }
 
    vector<int> v;
 
    for (int i = 2; i <= n; i++){
        if (unite(1, i)){
            v.push_back(i);
        }
    }
 
    cout << v.size() << endl;
    for (int e : v){
        cout << 1 << " " << e << endl;
    }
 
 
 
 
    return 0;
}
