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
    ll sum;
    ll leftS;
};

const int MAXN = 2e5+1;
Node ST[4*MAXN];
int leftOf[4*MAXN], rightOf[4*MAXN], vals[MAXN], indexToNode[MAXN];


void buildTree(int l, int r, int node = 1){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node].leftS = vals[l];
        ST[node].sum = vals[l];
        indexToNode[l] = node;
        return;
    }
    int a = node*2, b = node*2+1;
    int mid = (l+r)/2;
    buildTree(l, mid, a);
    buildTree(mid+1, r, b);
    ST[node].sum = ST[a].sum + ST[b].sum;
    ST[node].leftS = max(ST[a].leftS, ST[a].sum + ST[b].leftS);
    return;
}

vector<ll> v;

void query(int l, int r, int node = 1){
    if (l == leftOf[node] && r == rightOf[node]){
        v.push_back(node);
        return;
    }
    int a = node*2, b = node*2+1;
    if (r <= rightOf[a]){
        return query(l, r, a);
    }
    if (l >= leftOf[b]){
        return query(l, r, b);
    }
    query(l, rightOf[a], a);
    query(leftOf[b], r, b);

    return;
}

void update1(int node){
    if (!node)return;
    int a = node*2, b = node*2+1;
    ST[node].sum = ST[a].sum + ST[b].sum;
    ST[node].leftS = max(ST[a].leftS, ST[a].sum + ST[b].leftS);

    return update1(node/2);
}

void update(int pos, ll x){
    int node = indexToNode[pos];
    ST[node].leftS = x;
    ST[node].sum = x;
    return update1(node/2);
}

int main(){
    scoobydoobydoo();
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++){
        cin >> vals[i];
    }
    buildTree(0, n-1);


    vector<ll> ans;

    while (q--){
        ll t, a, b; cin >> t >> a >> b;
        if (t == 1){
            update(a-1, b);
        } else {   
            query(a-1, b-1);
            Node lastNode = ST[v[0]];
            ll maxi = max(lastNode.leftS, lastNode.sum);
            for (int i = 1; i < v.size(); i++){
                Node thisNode = ST[v[i]];
                maxi = max(maxi, thisNode.leftS+lastNode.sum);
                maxi = max(maxi, lastNode.sum + thisNode.sum);
                maxi = max(maxi, lastNode.sum);
                maxi = max(maxi, lastNode.leftS);
                thisNode.sum = lastNode.sum + thisNode.sum;
                thisNode.leftS = max(lastNode.leftS, lastNode.sum + thisNode.leftS);
                lastNode = thisNode;
            }
            ans.push_back(max(maxi, (ll)0));
            v.clear();
        }
    }

    for (auto& e : ans){
        cout << e << "\n";
    }



    return 0;
}
