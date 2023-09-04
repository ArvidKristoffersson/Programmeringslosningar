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
#include <ext/pb_ds/assoc_container.hpp>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

ll linf = 1e15+1;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 2e5+2;
int startVals[MAXN];

int main(){
    scoobydoobydoo();
    Tree<pair<int,int>> ordered_tree;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> startVals[i];
        ordered_tree.insert({startVals[i], i});
    }

    vector<int> ans;    
    
    while (q--){
        char t; int a, b; cin >> t >> a >> b;
        if (t == '!'){
            ordered_tree.erase({startVals[a], a});
            startVals[a] = b;
            ordered_tree.insert({startVals[a], a});
        } else {
            ans.push_back(ordered_tree.order_of_key({b, 1e9+3}) - ordered_tree.order_of_key({a-1, 1e9+3}));
        }
    }

    for (auto& e : ans){
        cout << e << endl;
    }

    return 0;
}
