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

string board;

bool calc(ll q){
    ll i = 0;
    ll sum = 0;
    for (int j = 0; j < q && j < board.size(); j++){
        if (board[j] == '.'){
            sum++;
        }
    }

    ll j = q-1;
    if (sum >= 2)return true;
    while (j < board.size()){
        j++;
        if (board[j] == '.')sum++;
        if (board[i] == '.')sum--;
        i++;
        if (sum >= 2)return true;
    }
    
    return false;
}

ll binarySearch(){
    ll fir = 0, sec = 1e6+1;
    ll ret = -1;
    while (fir < sec){
        ll k = ceil((double)(fir+sec)/2);
        if (calc(k)){
            sec = k-1;
            ret = k;
        } else {
            fir = k;
        }
    }
    return ret;
}

int main(){
    scoobydoobydoo();
    ll rNum; cin >> rNum >> board;
    cout << binarySearch() - 2 << endl;
    
    return 0;
}
