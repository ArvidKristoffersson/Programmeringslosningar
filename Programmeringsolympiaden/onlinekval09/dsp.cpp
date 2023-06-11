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

const int MAXN = 1e3;
int arr[MAXN];

int main(){
    scoobydoobydoo();
    int n; cin >> n;
    vector<pair<string, pair<int, int>>> instr;
    int count = 0;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        if (s == "HALT"){
            instr.push_back({s, {-1, -1}});
        } else if (s == "INPUT" || s == "OUTPUT"){
            int a; cin >> a;
            instr.push_back({s, {a, -1}});
        } else {
            int a, b; cin >> a >> b;
            instr.push_back({s, {a, b}});
        }
    }

    for (int i = 0; i < instr.size(); i++){
        auto e = instr[i];
        if (e.first == "INPUT"){
            int q; cin >> q;
            arr[e.second.first] = q;
        } else if (e.first == "OUTPUT"){
            cout << arr[e.second.first] << endl;
        } else if (e.first == "ADD"){
            arr[e.second.second] += arr[e.second.first];
        } else if (e.first == "SUB"){
            arr[e.second.second] -= arr[e.second.first];
        } else if (e.first == "HALT"){
            return 0;
        } else if (e.first == "CONST"){
            arr[e.second.second] = e.second.first;
        } else if (e.first == "JNZ"){
            if (arr[e.second.first]){
                i = e.second.second-1;
            }
        }
    }

    


    return 0;
}
