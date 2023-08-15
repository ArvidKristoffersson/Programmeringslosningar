#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <unordered_map>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

double c, f;

ll binarySearch(int b){
    int x = 0, y = 1e6+1;
    ll ret = -1;
    while (x < y){
        double k = ceil((double)(x+y)/2);
        if (abs(k/(double)b - c) <= f){
            ret = k;
        }
        if (k/(double)b > c){
            y = k-1;
        } else {
            x = k;
        }
    }
    return ret;
}

int main(){
    scoobydoobydoo();
    cin >> c >> f;
    f += 1e-9;

    cout << fixed << setprecision(10);
    int a, b;
    
    for (int i = 1; i <= 1e6+1; i++){
        ll q = binarySearch(i);
        if(q != -1){
            b = i;
            a = q;
            goto done;
        }
    }

    done:
    
    cout << a << endl << b << endl;




    return 0;
}
