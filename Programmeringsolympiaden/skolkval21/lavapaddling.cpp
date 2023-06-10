#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

ll n, k, h;
vector<ll> v;

bool itWork(ll q){
    ll left = q;
    for (auto e : v){
        if (left*(k-1) > e)continue;
        if (e > left*k)return false;
        left -= e - left*(k-1);
    }

    return true;
}

ll binarySearch(){
    ll fir = 0, sec = 1e15+1;
    ll ret = -1;
    while (fir < sec){
        double k = ceil((double)(fir+sec)/2);
        if (itWork(k)){
            sec = k-1;
            ret = k;
        } else {
            fir = k;
        }
    }
    return ret;
}

int main(){
    cin >> n >> k >> h;
    for (int i = 0; i < n-1; i++){
        ll a; cin >> a;
        v.push_back(a*h);
    }


    cout << binarySearch() << endl;
    return 0;
}
