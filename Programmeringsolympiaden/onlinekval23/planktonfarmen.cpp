#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

int main(){
    long long int minimum, n, t, ans = 0; cin >> minimum >> n;
    vector<long long int> v;

    for (int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(all(v));
    int pek1 = 0, pek2 = v.size()-1;

    while (pek1 < pek2){
        if (v[pek1] * v[pek2] >= minimum){
            ans++;
            pek1++;
            pek2--;
        }
        else {
            pek1++;
        }
    }

    cout << ans << endl;

    return 0;
}
