#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define alL(x)  (x).begin(), (x).end()

typedef long long ll;

ll linf = 2e18;

const int MAXN = 3e5+1;

struct Edge {
    int a;
    int b;
    ll w;
};

struct Node {
    ll x;
    ll y;
    int ind;
};

bool compE(const Edge& e1, const Edge& e2){
    return e1.w < e2.w;
}

bool compN(const Node& n1, const Node& n2){
    return n1.y < n2.y;
}

vector<Edge> edgeList;
vector<Node> nodeList;

ll parent[MAXN], sill[MAXN];

ll rootOf(int x){
    return (x == parent[x] ? x : parent[x] = rootOf(parent[x]));
}

void merge(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (a == b)return;
    if (sill[a] < sill[b])swap(a, b);
    parent[b] = a;
    sill[a] += sill[b];
    return;
}

map<ll, set<pair<ll, ll>>> xM;


int hotel, house;

int main(){
    ll n, k; cin >> n >> k;
    house = 0;
    hotel = n-1;
    for (int i = 0; i < n; i++){
        Node T;
        cin >> T.x >> T.y;
        T.ind = i;  
        nodeList.push_back(T);
        xM[T.x].insert({T.y, T.ind});
        parent[i] = i;
        sill[i] = 0;
    }

    sort(nodeList.begin(), nodeList.end(), compN);


    for (auto& e : nodeList){
        int a = e.ind;
        ll x = e.x;
        auto it = xM[x].upper_bound({e.y, linf});
        ll yOfAbove;
        if (it == xM[x].end()){
            yOfAbove = linf;
        } else {
            yOfAbove = (*it).first;
        }

        it = xM[x-1].lower_bound({e.y, -1});
        while (it != xM[x-1].end()){
            if ((*it).first >= yOfAbove-1){
                break;
            } else {
                Edge E;
                E.w = (*it).first-e.y;
                E.a = a;
                E.b = (*it).second;
                edgeList.push_back(E);
            }
            it++;
        }


        it = xM[x+1].lower_bound({e.y, -1});
        if (it != xM[x+1].end()){
            while (it != xM[x+1].end()){
                if ((*it).first >= yOfAbove-1){
                    break;
                } else {
                    Edge E;
                    E.w = (*it).first-e.y;
                    E.a = a;
                    E.b = (*it).second;
                    edgeList.push_back(E);
                }
                it++;
            }
        }

    }

    if (house == hotel){
        cout << 0 << endl;
        return 0;
    }

    sort(edgeList.begin(), edgeList.end(), compE);
    

    for (auto& e : edgeList){
        merge(e.a, e.b);
        if (e.w >= k){
            cout << "NATT" << endl;
            return 0;
        }
        if (rootOf(house) == rootOf(hotel)){
            cout << e.w << endl;
            return 0;
        }
        
    }

    cout << "NATT" << endl;


    return 0;
}
