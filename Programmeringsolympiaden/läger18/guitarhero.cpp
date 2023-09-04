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
    bool LRI;
    bool LRD;
    int LD;
    int LI;
    int RD;
    int RI;
    int LN; 
    int RN;
    int M;
};

Node ST[4*MAXN];
int vals[MAXN], leftOf[4*MAXN], rightOf[4*MAXN];
int indexToNode[MAXN];
int n, m, q;

void buildTree(int l, int r, int node = 1){
    leftOf[node] = l;
    rightOf[node] = r;
    if (l == r){
        ST[node].LRI = true;
        ST[node].LRD = true;
        ST[node].LD = 1;
        ST[node].LI = 1;
        ST[node].RD = 1;
        ST[node].RI = 1,
        ST[node].LN = vals[l];
        ST[node].RN = vals[r];
        ST[node].M = 1;
        indexToNode[l] = node;
        return;
    }
    int a = node*2, b = node*2+1;   
    int mid = (l+r)/2;
    buildTree(l, mid, a);
    buildTree(mid+1, r, b);

    ST[node].LRI = false;
    ST[node].LRD = false;

    if (ST[a].LRI && ST[b].LRI && ST[a].RN <= ST[b].LN){
        ST[node].LRI = true;
    }
    if (ST[a].LRD && ST[b].LRD && ST[a].RN >= ST[b].LN){
        ST[node].LRD = true;
    }

    if (ST[a].LRI && ST[a].RN <= ST[b].LN){
        ST[node].LD = ST[a].LD + ST[b].LD - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].LD = ST[a].LD;
    }

    if (ST[b].LRI && ST[a].RN <= ST[b].LN){
        ST[node].RI = ST[a].RI + ST[b].RI - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].RI = ST[b].RI;
    }

    if (ST[a].LRD && ST[a].RN >= ST[b].LN){
        ST[node].LI = ST[a].LI + ST[b].LI - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].LI = ST[a].LI;
    }

    if (ST[b].LRD && ST[a].RN >= ST[b].LN){
        ST[node].RD = ST[a].RD + ST[b].RD - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].RD = ST[b].RD;
    }

    ST[node].M = max(ST[node].LD, ST[node].LI);
    ST[node].M = max(ST[node].M, ST[node].RD);
    ST[node].M = max(ST[node].M, ST[node].RI);
    ST[node].M = max(ST[node].M, ST[a].M);
    ST[node].M = max(ST[node].M, ST[b].M);

    ST[node].LN = ST[a].LN;
    ST[node].RN = ST[b].RN;

    if (ST[a].RN >= ST[b].LN){
        ST[node].M = max(ST[node].M, ST[a].RD + ST[b].LI - (ST[a].RN == ST[b].LN));
    }

    if (ST[a].RN <= ST[b].LN){
        ST[node].M = max(ST[node].M, ST[a].RI + ST[b].LD - (ST[a].RN == ST[b].LN));
    }


    return;
}

void update1(int node){
    if (node == 0)return;
    int a = node*2, b = node*2+1;
    ST[node].LRI = false;
    ST[node].LRD = false;

    if (ST[a].LRI && ST[b].LRI && ST[a].RN <= ST[b].LN){
        ST[node].LRI = true;
    }
    if (ST[a].LRD && ST[b].LRD && ST[a].RN >= ST[b].LN){
        ST[node].LRD = true;
    }

    if (ST[a].LRI && ST[a].RN <= ST[b].LN){
        ST[node].LD = ST[a].LD + ST[b].LD - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].LD = ST[a].LD;
    }

    if (ST[b].LRI && ST[a].RN <= ST[b].LN){
        ST[node].RI = ST[a].RI + ST[b].RI - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].RI = ST[b].RI;
    }

    if (ST[a].LRD && ST[a].RN >= ST[b].LN){
        ST[node].LI = ST[a].LI + ST[b].LI - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].LI = ST[a].LI;
    }

    if (ST[b].LRD && ST[a].RN >= ST[b].LN){
        ST[node].RD = ST[a].RD + ST[b].RD - (ST[a].RN == ST[b].LN);
    } else {
        ST[node].RD = ST[b].RD;
    }

    ST[node].M = max(ST[node].LD, ST[node].LI);
    ST[node].M = max(ST[node].M, ST[node].RD);
    ST[node].M = max(ST[node].M, ST[node].RI);
    ST[node].M = max(ST[node].M, ST[a].M);
    ST[node].M = max(ST[node].M, ST[b].M);

    ST[node].LN = ST[a].LN;
    ST[node].RN = ST[b].RN;

    if (ST[a].RN >= ST[b].LN){
        ST[node].M = max(ST[node].M, ST[a].RD + ST[b].LI - (ST[a].RN == ST[b].LN));
    }

    if (ST[a].RN <= ST[b].LN){
        ST[node].M = max(ST[node].M, ST[a].RI + ST[b].LD - (ST[a].RN == ST[b].LN));
    }

    update1(node/2);
    return;
}

void update(int index, int x){
    ST[indexToNode[index]].RN = x;
    ST[indexToNode[index]].LN = x;
    update1(indexToNode[index]/2);
    return;
}

vector<Node> query1(int l, int r, int node = 1){
    if (leftOf[node] == l && rightOf[node] == r){
        return {ST[node]};
    }
    int a = node*2, b = node*2+1;
    if (r <= rightOf[a]){
        return query1(l, r, a);
    }
    if (l >= leftOf[b]){
        return query1(l, r, b);
    }
    vector<Node> aV = query1(l, rightOf[a], a);
    vector<Node> bV = query1(leftOf[b], r, b);
    for (int i = 0; i < bV.size(); i++){
        aV.push_back(bV[i]);
    }
    return aV;
}

int query(int l, int r){
    vector<Node> v = query1(l, r);
    Node lastNode = v[0];
    int maxi = lastNode.M;

    for (int i = 1; i < v.size(); i++){
        Node newVals;  
        Node thisNode = v[i];
        newVals.LRI = false;
        newVals.LRD = false;
        if (lastNode.LRI && thisNode.LRI && lastNode.RN <= thisNode.LN){
            newVals.LRI = true;
        }
        if (lastNode.LRD && thisNode.LRD && lastNode.RN >= thisNode.LN){
            newVals.LRD = true;
        }

        if (lastNode.LRI && lastNode.RN <= thisNode.LN){
            newVals.LD = lastNode.LD + thisNode.LD - (lastNode.RN == thisNode.LN);
        } else {
            newVals.LD = lastNode.LD;
        }

        if (thisNode.LRI && lastNode.RN <= thisNode.LN){
            newVals.RI = lastNode.RI + thisNode.RI - (lastNode.RN == thisNode.LN);
        } else {
            newVals.RI = thisNode.RI;
        }

        if (lastNode.LRD && lastNode.RN >= thisNode.LN){
            newVals.LI = lastNode.LI + thisNode.LI - (lastNode.RN == thisNode.LN);
        } else {
            newVals.LI = lastNode.LI;
        }

        if (thisNode.LRD && lastNode.RN >= thisNode.LN){
            newVals.RD = lastNode.RD + thisNode.RD - (lastNode.RN == thisNode.LN);
        } else {
            newVals.RD = thisNode.RD;
        }

        newVals.M = max(newVals.LD, newVals.LI);
        newVals.M = max(newVals.M, newVals.RD);
        newVals.M = max(newVals.M, newVals.RI);
        newVals.M = max(newVals.M, lastNode.M);
        newVals.M = max(newVals.M, thisNode.M);
        newVals.LN = lastNode.LN;
        newVals.RN = thisNode.RN;

        if (lastNode.RN >= thisNode.LN){
            newVals.M = max(newVals.M, lastNode.RD + thisNode.LI - (lastNode.RN == thisNode.LN));
        }
        if (lastNode.RN <= thisNode.LN){
            newVals.M = max(newVals.M, lastNode.RI + thisNode.LD - (lastNode.RN == thisNode.LN));
        }

        maxi = max(maxi, newVals.M);
        lastNode = newVals;

    }

    
    return maxi;
}


int main(){
    scoobydoobydoo();
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++){
        cin >> vals[i];
    }

    buildTree(0, n-1);

    vector<string> ans;

    while (q--){
        int a, b; cin >> a >> b;
        a--; b--;
        int w = query(a, b);
        if (w <= m){
            ans.push_back("ja");
        } else {
            ans.push_back("nej");
        }
    }

    for (auto& e : ans){
        cout << e << endl;
    }



    return 0;
}
