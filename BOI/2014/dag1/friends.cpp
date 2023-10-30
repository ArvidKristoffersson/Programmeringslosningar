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
 
const int MAXN = 2e6+1;
bool mem[MAXN][2];
int pref[MAXN][2];
int parent[MAXN];
int sill[MAXN];
int n;
 
bool foundFromRight;
 
int whatLetter[MAXN][30];
int letterPref[MAXN][30];
 
int rootOf(int x){
    return (parent[x] == x ? x : parent[x] = rootOf(parent[x]));
}
 
void merge(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (sill[a] < sill[b])swap(a, b);
    parent[b] = a;
    sill[a] += sill[b];
}
 
int main(){
    scoobydoobydoo();
    cin >> n;
    string s; cin >> s;
    if (n%2 == 0){
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }
 
    int currentChecking = 0;
 
    sill[0] = 1;
    parent[0] = 0;
 
    for (int x = 1; x < n; x++){
        parent[x] = x;
        sill[x] = 1;
        if (s[x-1] == s[x]){
            merge(currentChecking, x);
        } else {
            currentChecking = x;
        }
    }   
 
    int jS = (n-1)/2;
    for (int i = 0; i <= n/2; i++){
        if (i + jS > n)break;
 
        if (s[i+jS] == s[i]){
            mem[i][0] = true;
        }
        if (s[i+jS+1] == s[i]){
            mem[i][1] = true;
        }
    }
 
    pref[0][0] = mem[0][0];
    pref[0][1] = mem[0][1];
 
    for (int i = 1; i < n; i++){
        pref[i][0] = pref[i-1][0] + mem[i][0];
        pref[i][1] = pref[i-1][1] + mem[i][1];
    }

    int works = -1;
    
    for (int i = 0; i <= n/2; i++){
        int leftJ = (i == 0 ? 0 : pref[i-1][1]);
        int rightJ = pref[n/2][0]-pref[i][0];
        if (leftJ+rightJ == jS){
            if (works != -1 && rootOf(works) != rootOf(i)){
                cout << "NOT UNIQUE" << endl;
                return 0;
            } else {
                foundFromRight = false;
                works = i;
            }
        }
    }
 
 
    for (int i = 0; i < n; i++){
        pref[i][0] = 0;
        pref[i][1] = 0;
        mem[i][0] = false;
        mem[i][1] = false;
    }
 
    for (int i = n/2; i < n; i++){
        if (s[i-jS] == s[i]){
            mem[i][0] = true;
        }
        if (s[i-jS-1] == s[i]){
            mem[i][1] = true;
        }
    }
 
    pref[n-1][0] = mem[n-1][0];
    pref[n-1][1] = mem[n-1][1];
 
 
    for (int i = n-2; i >= 0; i--){
        pref[i][0] = pref[i+1][0] + mem[i][0];
        pref[i][1] = pref[i+1][1] + mem[i][1];
    }
 
    for (int i = n-1; i >= n/2; i--){
        int rightJ = (i == n-1 ? 0 : pref[i+1][1]);
        int leftJ = pref[n/2][0]-pref[i][0];
        if (leftJ+rightJ == jS){
            if (works != -1 && works != i && rootOf(works) != rootOf(i)){
                cout << "NOT UNIQUE" << endl;
                return 0;
            } else {
                foundFromRight = true;
                works = i;
            }
        }
    }
 
    if (works == -1){
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }
    string ans = "";
 
    if (foundFromRight){
        for (int i = n/2; i < works; i++){
            ans += s[i];
        }
        for (int i = works+1; i < n; i++){
            ans += s[i];
        }
        cout << ans << endl;
        return 0;
    }
 
    for (int i = 0; i < works; i++){
        ans += s[i];
    }
    for (int i = works+1; i <= n/2; i++){
        ans += s[i];
    }
 
    cout << ans << endl;
 
 
    return 0;
}
