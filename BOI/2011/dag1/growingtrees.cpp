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
 
struct Node {
    int x;
    int y;
    int lzAdd;
};
 
const int MAXN = 8e5+7;
 
Node ST[MAXN];
int leftOf[MAXN], rightOf[MAXN];
vector<int> vals;
 
void buildTree(int l, int r, int node = 1){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node].x = vals[l];
        ST[node].y = vals[r];
        ST[node].lzAdd = 0;
        return;
    }
    int mid = (l+r)/2;
    buildTree(l, mid, 2*node);
    buildTree(mid+1, r, 2*node+1);
    ST[node].x = ST[2*node].x;
    ST[node].y = ST[2*node+1].y;
    ST[node].lzAdd = 0;
    return;
}
 
void pushdown(int node){
    int a = 2*node, b = 2*node+1;
    ST[a].x += ST[node].lzAdd;
    ST[a].y += ST[node].lzAdd;
    ST[b].x += ST[node].lzAdd;
    ST[b].y += ST[node].lzAdd;
    ST[b].lzAdd += ST[node].lzAdd;
    ST[a].lzAdd += ST[node].lzAdd;
    if (leftOf[a] == rightOf[a])ST[a].lzAdd = 0;
    if (leftOf[b] == rightOf[b])ST[b].lzAdd = 0;
    ST[node].lzAdd = 0;
}
 
void update(int l, int r, int node = 1){
    if (leftOf[node] == l && rightOf[node] == r){
        ST[node].lzAdd++;
        if (leftOf[node] == rightOf[node])ST[node].lzAdd = 0;
        ST[node].x++;
        ST[node].y++;
        return;
    }
    int a = 2*node, b = 2*node+1;
    pushdown(node);
    if (r <= rightOf[a]){
        update(l, r, a);
    } else if (l >= leftOf[b]){
        update(l, r, b);
    } else {
        update(l, rightOf[a], a);
        update(leftOf[b], r, b);
    }
    ST[node].x = ST[a].x;
    ST[node].y = ST[b].y;
    return;
}
 
int findLC(int l, int r, int val, int node = 1){
    if (l == r){
        return l;
    }
    int a = 2*node, b = 2*node+1;
    pushdown(node);
    if (val <= ST[a].y){
        return findLC(l, rightOf[a], val, a);
    } else {
        return findLC(leftOf[b], r, val, b);
    }
}
 
int findRC(int l, int r, int val, int node = 1){
    if (l == r){
        return l;
    }
    int a = 2*node, b = 2*node+1;
    pushdown(node);
    if (val >= ST[b].x){
        return findRC(leftOf[b], r, val, b);
    } else {
        return findRC(l, rightOf[a], val, a);
    }
}
 
int fetchIndex(int x, int node = 1){
    if (leftOf[node] == rightOf[node]){
        return ST[node].x;
    }
    int a = 2*node, b = 2*node+1;
    pushdown(node);
    if (x <= rightOf[a]){
        return fetchIndex(x, a);
    } else {
        return fetchIndex(x, b);
    }
}
 
int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        vals.push_back(t);
    }
 
    sort(all(vals));
 
    buildTree(0, n-1);
 
    vector<ll> ans;
 
    while (q--){
        char c; cin >> c;
        if (c == 'F'){
            int ci, h; cin >> ci >> h;
            int Lc = findLC(0, n-1, h);
            int orWorth = fetchIndex(Lc);
            if (Lc == n-1 && orWorth < h)continue;
            if (Lc + ci - 1 < n){
                int x = fetchIndex(Lc + ci - 1);
                int Rx = findRC(0, n-1, x);
                int Lx = findLC(0, n-1, x);
                if (x == orWorth){
                    update(Rx-ci+1, Rx);
                    continue;
                }
                update(Lc, Lx-1);
                update(Rx-ci+Lx-Lc+1, Rx);
            } else {
                update(Lc, n-1);
            }
        } else {
            int mi, ma; cin >> mi >> ma;
            int Rmax = findRC(0, n-1, ma);
            int Lmi = findLC(0, n-1, mi);
 
            if (Lmi > Rmax || ma < ST[1].x || mi > ST[1].y){
                ans.push_back(0);
            } else {
                ans.push_back(Rmax-Lmi+1);
            }

        }

    }
 
    for (auto& e : ans){
        cout << e << endl;
    }
 
    return 0;
}
