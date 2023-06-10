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
#define rall(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

inline void scoobydoobydoo()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    scoobydoobydoo();

    ll n, k; cin >> n >> k;
    ll tvShow[k+1];
    for (int i = 1; i < k+1; i++){
        cin >> tvShow[i];
    }

    priority_queue<pair<ll, vector<ll> > > pq;

    for (int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        vector<ll> temp(b);
        for (int j = 0; j < b; j++){
            cin >> temp[j];
        }
        pq.push({-a, temp});
        temp.clear();
    }



    ll curDay = 0, time;
    ll timeLeft = 0;
    while (!pq.empty()){
        time = (-pq.top().first - curDay) * 10 + timeLeft;
        vector<ll> v = pq.top().second;

        for (auto e : v){
            time -= tvShow[e];
            tvShow[e] = 0;
        }

        if (time < 0){
            cout << "Nej" << endl;
            return 0;
        }

        timeLeft = time;

        curDay = -pq.top().first + 1;
        pq.pop();
    }



    



    cout << "Ja" << endl;


    return 0;
}
