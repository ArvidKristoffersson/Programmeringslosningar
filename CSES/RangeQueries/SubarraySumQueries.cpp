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

const int MAXN = 2e5+1;
struct Node {
    ll S;
    ll L;
    ll R;
    ll M;
};

Node ST[4*MAXN];
int vals[MAXN];
map<int, int> indexToNode;

void buildTree(int l, int r, int node){
    if (l == r){
        indexToNode[l] = node;
        ST[node].L = vals[l];
        ST[node].R = vals[l];
        ST[node].M = vals[l];
        ST[node].S = vals[l];
        return;
    }
    int a = 2*node, b = 2*node+1;
    int mid = (l+r)/2;
    buildTree(l, mid, a);
    buildTree(mid+1, r, b);
    ST[node].L = max(ST[a].L, ST[a].S + ST[b].L);
    ST[node].R = max(ST[b].R, ST[b].S + ST[a].R);
    ST[node].M = max(max(ST[a].M, ST[b].M), ST[a].R+ST[b].L);
    ST[node].S = ST[a].S + ST[b].S;
    return;
}

void update1(int node){
    if (node == 0)return;
    int a = 2*node, b = 2*node+1;
    ST[node].L = max(ST[a].L, ST[a].S + ST[b].L);
    ST[node].R = max(ST[b].R, ST[b].S + ST[a].R);
    ST[node].M = max(max(ST[a].M, ST[b].M), ST[a].R+ST[b].L);
    ST[node].S = ST[a].S + ST[b].S;
    return update1(node/2);
}

void update(int node, int x){
    ST[node].S = x;
    ST[node].M = x;
    ST[node].L = x;
    ST[node].R = x;
    update1(node/2);
}


int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> vals[i];
    }
    buildTree(0, n-1, 1);
    vector<ll> ans;

    while (m--){
        int a, b; cin >> a >> b;
        update(indexToNode[a-1], b);
        ans.push_back(max(ST[1].M, (ll)0));
    }

    for (auto& e : ans){
        cout << e << endl;
    }



    return 0;
}
