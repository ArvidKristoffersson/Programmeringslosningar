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

const int MAXN = 8e5+1;

int ST[MAXN];
int leftOf[MAXN], rightOf[MAXN];
int hotels[MAXN];
map<int, int> indexToNode;

void buildTree(int node, int l, int r){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node] = hotels[l];
        indexToNode[l] = node;
        return; 
    }

    int mid = (l+r)/2;
    buildTree(node*2, l, mid);
    buildTree(node*2+1, mid+1, r);
    ST[node] = max(ST[node*2], ST[node*2+1]);
    return;
}

void update1(int node){
    if (node == 0)return;
    ST[node] = max(ST[node*2], ST[node*2+1]);
    update1(node/2);
}

void update(int node, int x){
    ST[node] = x;
    return update1(node/2);
}

int query(int node, int l, int r, int x){
    if (x > ST[1])return -1;
    if (l == r){
        ST[node] -= x;
        return l;
    }
    int a = node*2, b = node*2+1;
    int ret;

    if (ST[a] >= x)ret = query(a, l, rightOf[a], x);
    else ret = query(b, leftOf[b], r, x);
    ST[node] = max(ST[a], ST[b]);
    return ret;
}


int main(){
    scoobydoobydoo();
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> hotels[i];
    }
    
    vector<int> ans;
    buildTree(1, 0, n-1);

    while (m--){
        int a; cin >> a;
        int fir = query(1, 0, n-1, a);
        ans.push_back(fir+1);
    }

    for (auto& e : ans){
        cout << e << " ";
    }
    cout << endl;


    return 0;
}   
