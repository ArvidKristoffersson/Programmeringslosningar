#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define all(x)  (x).begin(), (x).end()

typedef long long ll;

using namespace std;

const int MAXN = 1e5+2;

vector<int> children[MAXN];
int parent[MAXN];
int value[MAXN];
vector<int> adj[MAXN];
bool isVisited[MAXN];
vector<int> ans;

void buildTree(int node){
    isVisited[node] = true;
    bool hasChild = false;

    for (auto e : adj[node]){
        if (!isVisited[e]){
            parent[e] = node;
            children[node].push_back(e);
            buildTree(e);
        }
    }
    return;
}


void upwardsDown(int node){
    if (children[node].empty()){
        value[node] = 0;
        return;
    }
    int maximus = -1;
    int x;
    for (auto e : children[node]){
        upwardsDown(e);
    }

    for (auto e : children[node]){
        if (value[e] > maximus){
            maximus = value[e];
            x = e;
        }
    }

    for (auto e : children[node]){
        if (e != x){
            ans.push_back(value[e]+1);
        }
    }
    value[node] = maximus+1;
    return;
}



int main(){
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    buildTree(0);
    int s = 1;
    for (int i = 1; i <= n; i++){
        isVisited[i] = false;
    }

    upwardsDown(0);

    ans.push_back(value[0]);
    sort(all(ans));
    int j = 1;

    for (int i = ans.size()-1; i > -1; i--){
        for (int k = 0; k < ans[i]; k++){
            cout << j << " ";
        }
        j++;
    }
    cout << endl;
    

    return 0;
}
