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

vector<int> vals;
const int MAXN = 8e5+1;
int ST[MAXN];
int leafIndex[MAXN];
map<int, int> indexToNode;


void buildTree(int l, int r, int node = 1){
    if (l == r){
        indexToNode[l] = node;
        leafIndex[node] = l+1;
        ST[node] = 1;
        return;
    }

    int mid = (l+r)/2;
    buildTree(l, mid, node*2);
    buildTree(mid+1, r, node*2+1);
    ST[node] = ST[node*2] + ST[node*2+1];
    return;
}

void update1(int node){
    if (!node)return;
    ST[node] = ST[node*2] + ST[node*2+1];
    return update1(node/2);
}

void update(int ind){
    ST[indexToNode[ind]] = 0;
    return update1(indexToNode[ind]/2);
}

int query(int x, int node = 1){
    if (leafIndex[node]){
        return leafIndex[node]-1;
    }
    int a = node*2, b = node*2+1;
    if (ST[a] >= x){
        return query(x, a);
    } else {
        return query(x-ST[a], b);
    }
}

int main() {
    int n; cin >> n;
    
    vector<int> ans;

    for (int i = 0; i < n; i++){
        int t; cin >> t;
        vals.push_back(t);
    }

    buildTree(0, n-1);

    while (n--){
        int t; cin >> t;
        int n = query(t);
        ans.push_back(vals[n]);
        update(n);
    }

    for (auto& e : ans){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
