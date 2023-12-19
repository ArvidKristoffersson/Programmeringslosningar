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
 
const int MAXN = 5e3+1;
vector<int> trusts[MAXN];
int visited[MAXN];
int n;
 
ll rootIt(int x){
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    visited[x] = true;
    ll sum = 1;
    int depth = 2;
    vector<int> cur = trusts[x];
    for (auto& e : cur){
        visited[e] = true;
    }
    while (!cur.empty()){
        sum += depth*cur.size();
        vector<int> nCur;
 
        for (auto& e : cur){
            for (int x : trusts[e]){
                if (!visited[x]){
                    visited[x] = true;
                    nCur.push_back(x);
                }
            }
        }
        cur = nCur;
 
        depth++;
    }
    bool isValid = true;
    for (int i = 0; i < n; i++)if (!visited[i])isValid = false;
 
 
    return (isValid ? sum : linf);
}
 
int main(){
    scoobydoobydoo();
    cin >> n;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            int t; cin >> t;
            trusts[--t].push_back(i);
        }
    }
 
    ll mini = linf;
 
    for (int i = 0; i < n; i++){
        mini = min(mini, rootIt(i));
    }
    cout << mini << endl;
 
    return 0;
}
