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

string mem[30][70];
int n;
string s;

string dp(int index, int highest){
    if (index == n)return "";
    if (mem[index][highest] != "")return mem[index][highest];
    string ret = "";
    if ((s[index]-'A') < highest)return mem[index][highest] = dp(index+1, highest);
    ret = dp(index+1, highest);

    string buy = dp(index+1, (s[index]-'A'));
    buy += s[index];

    if (buy.size() > ret.size())return mem[index][highest] = buy;
    else return mem[index][highest] = ret;
}


int main(){
    scoobydoobydoo();
    cin >> s;
    n = s.size();
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            mem[i][j] = "";
        }
    }
    
    string ans = dp(0, 0);
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
