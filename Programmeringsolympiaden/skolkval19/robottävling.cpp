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
    vector<int> left, right;

    int n; cin >> n;
    int ans = pow(n, 2);
    vector<bool> doneLeft(n, false), doneRight(n, false);
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        if (t == 1){
            doneLeft[i] = true;
        }
        left.push_back(t);
    }
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        if (t == 1){
            doneRight[i] = true;
        }
        right.push_back(t);
    }
    int max = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            max += min(left[i], right[j]);
        }
    }

    for (int i = 0; i < n; i++){
        if (!doneRight[i]){
            ans += right[i]-1;
            doneRight[i] = true;
            for (int j = 0; j < n; j++){
                if (!doneLeft[j] && right[i] == left[j]){
                    doneLeft[j] = true;
                    break;
                }
            }
        }
        if (!doneLeft[i]){
            ans += left[i]-1;
            doneLeft[i] = true;
            for (int j = 0; j < n; j++){
                if (!doneRight[j] && right[j] == left[i]){
                    doneRight[j] = true;
                    break;
                }
            }
        }
    }
    



    cout << ans << " " << max << endl;


    return 0;
}
