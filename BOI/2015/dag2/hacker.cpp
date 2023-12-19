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
 
int segmet[(int)1e8];
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int half = ceil((double)n/2.0);
    int startSum = 0;
    for (int i = 0; i < half; i++){
        startSum += v[i];
    }
 
    int i = 0, j = half-1;
    segmet[i] = startSum;
    while (i < n){
        j = (j+1)%n;
        startSum += v[j];
        startSum -= v[i++];
        segmet[i] = startSum;
    }
 
    multiset<int> ms;
    for (int i = 0; i < half; i++){
        ms.insert(segmet[i]);
    }
    int maxi = -1;
 
    i = 0; j = half-1;
 
    while (i < n){
        maxi = max(maxi, *ms.begin());
        auto it = ms.find(segmet[i]);
        ms.erase(it);
        i++;
        j = (j+1)%n;
        ms.insert(segmet[j]);
    }
 
    cout << maxi << endl;  
 
    return 0;
}
