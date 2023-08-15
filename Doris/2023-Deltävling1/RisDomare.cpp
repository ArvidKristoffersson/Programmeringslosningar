#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <unordered_map>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    string s; cin >> s;
    bool cool = false;
    if (s == "antal"){
        cool = true;
    } else {
        cool = false;
    }
    
    ll maximus = -1;
    ll ans = -1;
    ll bA, bB;
    
    for (int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        if (a + b > maximus){
            maximus = a+b;
            ans = i+1;
            bA = a;
            bB = b;
        } 
        if (a+b == maximus){
            if (cool && bA < a){
                bA = a;
                bB = b;
                ans = i+1;
            } else if (bB < b && !cool){
                bA = a;
                bB = b;
                ans = i+1;
            }
        }
    }
    
    cout << ans << endl;
    

    return 0;
}
