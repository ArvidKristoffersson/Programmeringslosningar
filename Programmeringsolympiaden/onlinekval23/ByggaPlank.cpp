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
    int n, k; cin >> n >> k;

    vector<pair<int, int>> boards;

    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        boards.push_back({a, i});
    }

    ll ans = 0;

    sort(all(boards));
    set<ll> s;
    s.insert(-1); s.insert(n);


    for (pair<int, int> p : boards){
        int height = p.first;
        int index = p.second;

        s.insert(index);
        auto itr = s.find(index);
        auto left = itr, right = itr;
        left--; right++;
        int i = 0;

        while (i < k){
            if (left == s.begin())break;
            left--;
            i++;
        }

        while (i < k){
            right++;
            i++;
            if (right == s.end()){
                right--;
                break;
            }
        }

        while (left != itr && right != s.end()){
            ans = max<ll>(ans, (*right - *left - 1)*height);

            left++;
            right++;
        }



    }

    cout << ans << endl;

    return 0;
}
