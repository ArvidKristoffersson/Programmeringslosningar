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

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    vector<int> real, fake;
    
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        fake.push_back(t);
        real.push_back(t);

    }
    
    sort(all(real));
    
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        if (real[i] != fake[i]){
            sum++;
        }
    }
    
    cout << sum << endl;


    return 0;
}
