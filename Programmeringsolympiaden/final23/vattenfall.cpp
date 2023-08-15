#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void printSet(set<ll> setOfCool){
    for (auto e : setOfCool){
        cout << e << " ";
    }
    cout << endl;
    return;
}

ll r, c, k, n;
map<ll, bool> M;
set<ll> s;
map<pair<ll, ll>, bool> stone;
priority_queue<pair<ll, ll>> pq;

int main(){
    scoobydoobydoo();
    cin >> r >> c >> k >> n;

    for (int i = 0; i < k; i++){
        ll t; cin >> t;
        M[t] = true;
        s.insert(t);
    }

    for (int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        pq.push({a, b});
        stone[{a, b}] = true;
    }

    while (!pq.empty()){
        ll x = pq.top().first;
        ll y = pq.top().second;
        pq.pop();
        if (M[y]){
            for (int i = -1; y+i > -1; i--){
                if (stone[{x+1, y+i}]){
                    break;
                }
                if (!stone[{x, y+i}]){
                    M[y+i] = true;
                    s.insert(y+i);
                    break;
                } else if (M[y+i]){
                    M[y+i] = false;
                    s.erase(y+i);
                }
            }
            for (int i = 1; y+i < c; i++){
                if (stone[{x+1, y+i}]){
                    break;
                }
                if (!stone[{x, y+i}]){
                    M[y+i] = true;
                    s.insert(y+i);
                    break;
                } else if (M[y+i]){
                    M[y+i] = false;
                    s.erase(y+i);
                }
            }
            s.erase(y);
            M[y] = false;
        }
    }


    cout << s.size() << endl;


    return 0;
}
