//40 poäng
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
    string s; cin >> s;
    int n; cin >> n;
    vector<string> vec; 
    for (int i = 0; i < n; i++){
        string c; cin >> c;
        if (c.size() > s.size())continue;
        vec.push_back(c);
    }
    ll ans = 0;
    for (auto str : vec){
        bool survived = true;
        int j = 0;
        for (int i = 0; i < str.size(); i++){
            char cur = str[i];
            bool foundIt = false;
            while (j < s.size()){
                if (s[j] == cur){
                    j++;
                    foundIt = true;
                    break;
                }


                j++;
            }
            if (j == s.size() && !foundIt){
                survived = false;
            }

        }
        if (survived){
            ans++;
        }
    }

    cout << ans << endl;




    return 0;
}
