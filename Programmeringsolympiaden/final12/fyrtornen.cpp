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

const int MAXN = 5e5+1;

unordered_map<int, vector<int> > xM, yM;
pair<int, int> torn[MAXN];
int parent[MAXN];
int sill[MAXN];
bool isVisited[MAXN], isVis[MAXN];

int rootOf(int node){
    return (parent[node] == node ? node : parent[node] = rootOf(parent[node]));
}

void merge(int a, int b){
    a = rootOf(a);
    b = rootOf(b);
    if (a == b)return;
    //cout << "M: " <<  a << " " << b << endl;
    
    if (sill[a] < sill[b])swap(a, b);
    sill[a] += sill[b];
    //cout << s.size() << endl;
    parent[b] = a;
}

void dfs(int node){
    isVisited[node] = true;
    int x = torn[node].first;
    int y = torn[node].second;
    for (auto& e : xM[x]){
        merge(node, e);
        if (!isVisited[e])dfs(e);
    }
    for (auto& e : yM[y]){
        merge(node, e);
        if (!isVisited[e])dfs(e);
    }
    return;
}

int main(){
    scoobydoobydoo();
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        xM[x].push_back(i);
        yM[y].push_back(i);
        torn[i] = {x, y};
        parent[i] = i;
        sill[i] = 1;
    }


    for (int i = 0; i < m; i++){
        if (!isVisited[i])dfs(i);
    }
    vector<int> s;


    for (int i = 0; i < m; i++){
        int a = rootOf(i);
        if (!isVis[a]){
            isVis[a] = true;
            s.push_back(sill[a]);
        }
    }

    sort(rall(s));
    ll sum = 0;
    for (int i = 0; i < k; i++){
        sum += s[i];
    }

    cout << sum << endl;



    return 0;
}
