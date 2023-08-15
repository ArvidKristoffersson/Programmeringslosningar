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
 
struct M {
    ll a, b, c, d;
};
 
const int MOD = 1e9+7;
 
M matrixMut(M m1, M m2){
    M ret;
    ret.a = (m1.a*m2.a + m1.b*m2.c)%MOD;
    ret.b = (m1.a*m2.b + m1.b*m2.d)%MOD;
    ret.c = (m1.c*m2.a + m1.d*m2.c)%MOD;
    ret.d = (m1.c*m2.b + m1.d*m2.d)%MOD;
 
    return ret;
}
 
 
void printM(M m){
    cout << m.a << " " << m.b << endl;
    cout << m.c << " " << m.d << endl;
    return;
}
 
 
 
int main(){
    scoobydoobydoo();
 
    ll n; cin >> n;
    cout << fixed << setprecision(0);
    M mainM;
    mainM.a = 1;
    mainM.b = 1;
    mainM.c = 1;
    mainM.d = 0;
 
    M result;
    result.a = 1;
    result.b = 0;
    result.c = 0;
    result.d = 1;

 
    while (n){
        if (n&1)result = matrixMut(result, mainM);
 
        mainM = matrixMut(mainM, mainM);
 
        n = n >> 1;
    }
 
 
    cout << result.b << endl;
 
 
    return 0;
}
