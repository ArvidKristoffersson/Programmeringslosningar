#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()

typedef long long ll;

using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    queue<ll> q;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++){
        ll t; cin >> t;
        q.push(t);
    }
    for (int i = 0; i < m; i++){
        pq.push(-i);
    }

    ll maxDone = 0;
    bool done = false;

    while (!pq.empty() && !done){
        if (q.empty()){
            done = true;
            break;
        }
        ll w = -pq.top();
        pq.pop();
        ll c = q.front();
        q.pop();

        pq.push(-(w+c*m));
        maxDone = max(maxDone, w+c*m);

    }

    cout << maxDone << endl;


    return 0;
}
