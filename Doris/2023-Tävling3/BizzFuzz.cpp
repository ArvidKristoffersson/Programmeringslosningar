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

ll gcd(ll x, ll y){
    return (x%y ? gcd(y,x%y) : y);
}

int main(){
    scoobydoobydoo();
    ll a, b, c, d; cin >> a >> b >> c >> d;
    
    if (a > b)swap(a, b);

    ll o = c*d/gcd(c, d);

    cout << b/o - (a-1)/o << endl;



    return 0;
}
