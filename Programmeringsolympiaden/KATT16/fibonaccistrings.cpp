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

const int MAXN = 1e5+1;
ll counter[MAXN];
ll found[MAXN];
ll zeroes[MAXN];

ll fibonacci(int n, char s[]){
    if (s[n-1] == 'a'){
        found[n-1] = 1;
        counter[n-1]  = 1;
        zeroes[n-1] = 0;
    } else {
        found[n-1] = 0;
        counter[n-1] = 0;
        zeroes[n-1] = 1;
    }

    for (int i = n-2; i >= 0; i--){
        if (s[i] == 'b'){
            found[i] = found[i+1];
            counter[i] = counter[i+1];
            zeroes[i] = zeroes[i+1]+1;
        } else if (s[i] == 'a' && s[i+1] == 'a'){
            counter[i] = 1;
            found[i] = 1;
            zeroes[i] = 0;
        } else {
            counter[i] = counter[i+1] + 1 + zeroes[i+1];
            found[i] = counter[i+1] + zeroes[i+1] + found[i+1] + 1;
            zeroes[i] = 0;
        }
    }

    ll sum = 0;

    for (int i = 0; i < n; i++){
        sum += found[i];
    }
    
    return sum;
}
