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
    int T, b; cin >> T >> b;
    map<string, int> M;
    vector<int> v(b);
    vector<int> ans(b);

    for (int i = 0; i < b; i++){
        cin >> v[i];
    }

    for (int i = 0; i < T; i++){
        string s; cin >> s;
        int t; cin >> t;
        M[s] = t;
    }

    for (int i = 0; i < b; i++){
        for (int j = 0; j < v[i]; j++){
            string s; cin >> s;
            int t; cin >> t;
            ans[i] += M[s] - t;
        }
    }

    for (auto& e : ans){
        cout << e << endl;
    }



    return 0;
}
