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
const int MAXN = 2e5+1;
int parent[MAXN], sill[MAXN];

int rootOf(ll x){
    return (x == parent[x] ? x : parent[x] = rootOf(parent[x]));
}

bool unite(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (a == b)return false;
    if (sill[a] < sill[b])swap(a, b);
    sill[a] += sill[b];
    parent[b] = a;
    return true;
}

int main(){
    scoobydoobydoo();
    vector<pair<int, int>> unused;
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++){
        parent[i] = i;
        sill[i] = 1;
    }

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        if (!unite(x, y)){
            unused.push_back({x, y});
        }
    }
    int zeroRoot = rootOf(0);
    int bridgesLeft = unused.size();
    vector<pair<int, int> > needs;

    for (int i = 1; i < n; i++){
        if (unite(0, i)){
            needs.push_back({0, i});
        }
    }

    if (bridgesLeft < needs.size()){
        cout << "Nej" << endl;
        return 0;
    }

    cout << "Ja" << endl;
    cout << needs.size() << endl;

    for (int i = 0; i < needs.size(); i++){
        cout << unused[i].first+1 << " " << unused[i].second+1 << " " << needs[i].first+1 << " " << needs[i].second+1 << endl;
    }




    return 0;
}
