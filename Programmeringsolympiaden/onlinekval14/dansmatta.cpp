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

const int MAXN = 1e4+1;
int mem[MAXN][5][5];
int n;

vector<string> v;

int dp(int index, int pressedDown1, int pressedDown2){
    if (index == n)return 0;
    if (mem[index][pressedDown1][pressedDown2] != -1)return mem[index][pressedDown1][pressedDown2];
    int extra = 0;
    vector<char> reserved;
    for (auto& c : v[index]){
        if (c == 'V' && pressedDown1 != 0 && pressedDown2 != 0){
            extra++;
        } else if (c == 'U' && pressedDown1 != 1 && pressedDown2 != 1){
            extra++;
        } else if (c == 'H' && pressedDown1 != 2 && pressedDown2 != 2){
            extra++;
        } else if (c == 'N' && pressedDown1 != 3 && pressedDown2 != 3){
            extra++;
        } else {
            reserved.push_back(c);
        }
    }
    int nPres1 = pressedDown1, nPres2 = pressedDown2;
    if (v[index].size() == 1){
        int s;
        char c = v[index][0];
        if (c == 'V')s = 0;
        else if (c == 'U')s = 1;
        else if (c == 'H')s = 2;
        else s = 3;
        return mem[index][pressedDown1][pressedDown2] = extra + min(dp(index+1, s, pressedDown2), dp(index+1, pressedDown1, s));
    } else {
        int s, q;
        char c = v[index][0];
        if (c == 'V')s = 0;
        else if (c == 'U')s = 1;
        else if (c == 'H')s = 2;
        else s = 3;
        char c1 = v[index][1];
        if (c1== 'V')q = 0;
        else if (c1 == 'U')q = 1;
        else if (c1 == 'H')q = 2;
        else q = 3;
        return mem[index][pressedDown1][pressedDown2] = extra + min(dp(index+1, q, s), dp(index+1, s, q));

    }
    
}

int main(){
    scoobydoobydoo();
    cin >> n;
    for (int i = 0; i < n; i++){
        string l; cin >> l;
        v.push_back(l);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                mem[i][j][k] = -1;
            }
        }
    }

    cout << dp(0, 0, 2) << endl;

    return 0;
}
