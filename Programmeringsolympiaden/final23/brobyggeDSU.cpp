#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

const int MAXN = 1e5+3;
ll p[MAXN], s[MAXN];

ll r(ll x){
    return (x == p[x] ? x : p[x] = r(p[x]));
}

void u(ll a, ll b){
    a = r(a);
    b = r(b);
    if (a == b)return;
    if (s[a] < s[b])swap(a, b);
    s[a] += s[b];
    p[b] = a;
}

map<pair<ll, ll>, ll> M;

void f(pair<ll, ll> q, ll i){
    if (M.find(q) != M.end())u(i, M[q]);
}

int main(){
    ll n, m, t; cin >> n >> m >> t;
    for (ll i = 0; i <= t+1; i++){
        p[i] = i;
        s[i] = 1;
    }

   

    for (ll i = 1; i <= t; i++){
        ll x, y; cin >> x >> y;
        if (x == 1)u(0, i);
 
        if (x == n-2)u(t+1, i);

        f({x-1, y}, i);
        f({x+1, y}, i);
        f({x, y-1}, i);
        f({x, y+1}, i);

        M[{x, y}] = i;

        if (r(0) == r(t+1)){
            cout << i << endl;
            exit(0);
        }
        
    }

    cout << "nej" << endl;

    exit(0);
}
