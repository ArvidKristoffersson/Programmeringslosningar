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

int main(){
    scoobydoobydoo();
    int x, cb, y, cs, n; cin >> x >> cb >> y >> cs >> n;
    vector<pair<ll, pair<int, int> > > allComb;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            allComb.push_back({i*cb+j*cs, {i, j}});
        }
    }

    sort(all(allComb));

    int a = 0, b = allComb.size();
    int ret = -1;
    while (a < b){
        int k = (a+b)/2;
        int sum = 1;
        int nX = x-allComb[k].second.first, nY = y-allComb[k].second.second;
        for (int i = k; i < allComb.size(); i++){
            bool canBuy = true;
            while (canBuy){
                if (nX-allComb[i].second.first < 0 || nY-allComb[i].second.second < 0){
                    canBuy = false;
                    break;
                }
                sum++;
                nX -= allComb[i].second.first;
                nY -= allComb[i].second.second;
            }
            if (nX <= 0 && nY <= 0)break;
        }  
        if (sum >= n){
            ret = k;
            a = k+1;
        } else {
            b = k;
        }
    }


    cout << allComb[ret].first << endl;


    return 0;
}
