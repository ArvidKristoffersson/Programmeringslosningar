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
    string acN = "";
    int maxi = -1;

    while (n--){
        char c; cin >> c;
        if (c -'0' < 10 && c-'0' >= 0){
            acN += c;
        } else {
            int l = 0;
            if (!acN.empty())l = stoi(acN);
            maxi = max(maxi, l);
            acN = "";
        }
    }
    int l = 0;
    if (!acN.empty())l = stoi(acN);
    maxi = max(maxi, l);
    acN = "";

    

    cout << maxi << endl;



    return 0;
}
