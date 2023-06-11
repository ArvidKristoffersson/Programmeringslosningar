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

ll n, K;
vector<ll> v;

bool itWork(ll q){
    ll sum = 0;
    for (int i = 0; i < v.size()-1; i++){
        if (v[i+1] - v[i] < q){
            i++;
            sum++;
        }
    }

    if (sum >= K){
        return true;
    }

    return false;
}


ll binarySearch(){
    ll fir = 0, sec = 1e15+1;
    ll ret = -1;

    while (fir < sec){
        double k = ceil((double)(fir+sec)/2);
        if (itWork(k)){
            ret = k;
            sec = k-1;
        } else {
            fir = k;
        }
    }


    return ret;
}

int main(){
    scoobydoobydoo();
    cin >> n >> K;

    for (int i = 0; i < n; i++){
        ll t; cin >> t;
        v.push_back(t);
    }

    sort(all(v));


    cout << binarySearch() << endl;


    return 0;
}
