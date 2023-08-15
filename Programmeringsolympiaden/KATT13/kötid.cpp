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

vector<int> v;
const int MAXN = 8e6+1;

int ST[MAXN], leftOf[MAXN], rightOf[MAXN];
map<int, int> posToNode;

int buildTree(int l, int r, int node = 1){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        posToNode[l] = node;
        return ST[node] = v[l];
    }
    int mid = (l+r)/2;
    return ST[node] = min(buildTree(l, mid, node*2), buildTree(mid+1, r, node*2+1));
}

int query(int x, int l, int r, int node = 1){
    if (x < ST[1])return -1;
    if (l == r){
        return l;
    }
    int a = node*2;
    int b = node*2+1;

    if (ST[a] <= x){
        return query(x, l, rightOf[a], a);
    } else {
        return query(x, leftOf[b], r, b);
    }
}

void update(int pos){
    ST[posToNode[pos]] = 1e9;
    int node = posToNode[pos]/2;
    while (node){
        ST[node] = min(ST[node*2], ST[node*2+1]);
        node /= 2;
    }
    return;
}

int whenGotOn[MAXN];

int main(){
    scoobydoobydoo();
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }


    buildTree(0, n-1);


    int counter = 1;

    for (int i = 0; i < n; i++){
        if (whenGotOn[i])continue;
        int el = v[i];
        int c = k - el;
        whenGotOn[i] = counter;

        update(i);
        int q = 0;

        while (q != -1){
            q = query(c, i, n-1);
            if (q != -1){
                whenGotOn[q] = counter;
                update(q);
                c -= v[q];
            }
        }



        counter++;
    }


    for (int i = 0; i < n; i++){
        cout << whenGotOn[i]-1 << " ";
    }
    cout << endl;


    return 0;
}
