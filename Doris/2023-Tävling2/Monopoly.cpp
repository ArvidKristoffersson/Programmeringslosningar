#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    double tab[13];
    cout << fixed << setprecision(7);
    int a = 2, b = 12;
    for (double x = 1.0/36.0; a <= b; x += 1.0/36.0){
        //cout << x << " " << a << " " << b << endl;
        tab[a++] = x;
        tab[b--] = x;
    }

    double sum = 0;

    for (auto e : v){
        sum += tab[e];
    }

    cout << sum << endl;





    return 0;
}
