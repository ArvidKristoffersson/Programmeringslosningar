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
vector<int> childs[MAXN];
int subords[MAXN];
 
int dfs(int node){
    if (childs[node].empty()){
        subords[node] = 0;
        return 1;
    }
 
    int sum = 0;
    for (auto& e : childs[node]){
        sum += dfs(e);
    }
    subords[node] = sum;
 
    return sum+1;
}
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int t; cin >> t;
        t--;
        childs[t].push_back(i);
    }
 
    dfs(0);
 
    for (int i = 0; i < n; i++){
        cout << subords[i] << " ";
    }
    cout << endl;
 
 
 
 
    return 0;
}
