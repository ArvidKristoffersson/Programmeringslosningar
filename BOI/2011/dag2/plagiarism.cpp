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
 
int main(){
    scoobydoobydoo();
    int n; cin >> n;
    vector<int> v(n);
    vector<double> extra(n);
 
    for (int i = 0; i < n; i++){
        cin >> v[i];
        extra[i] = (double)v[i]*0.9;
    }
 
    sort(all(v));
    sort(all(extra));
 
    int j = 0;
 
    ll sum = 0;
    for (int i = 0; i < n; i++){
        while (extra[i] > v[j] && j < i){
            j++;
        }
        sum += (i-j);
    }
 
    cout << sum << endl;
 
    return 0;
}
