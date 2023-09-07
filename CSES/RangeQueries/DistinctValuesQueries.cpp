#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
 
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
const int MAXN = 2e5+1;
 
bool customOp(const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2){
    return p1.first.first > p2.first.first;
}
 
map<int, int> lastUsedIndex;
int vals[MAXN];
int BIT[MAXN];
int ans[MAXN];
 
int n, q;
 
vector<pair<pair<int, int>, int> > queries;
 
int query(int node){
    int sum = 0;
    while (node){
        sum += BIT[node];
        node -= node&(~node+1);
    }
    return sum;
}
 
void update(int index, int x){
    while (index <= n){
        BIT[index] += x;
        index += index&(~index+1);
    }
}
 
void buildFrom(int a, int b){
    for (int i = a; i >= b; i--){
        if (lastUsedIndex.find(vals[i]) != lastUsedIndex.end()){
            update(lastUsedIndex[vals[i]], -1);
            lastUsedIndex[vals[i]] = i;
            update(i, 1);
        } else {
            lastUsedIndex[vals[i]] = i;
            update(i, 1);
        }
    }
}
 
 
 
int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> vals[i];
    }
    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        queries.push_back({{a, b}, i});
    }
 
    sort(all(queries), customOp);
 
    int lastA = n;
    for (int i = 0; i < q; i++){
        auto e = queries[i];
        buildFrom(lastA, e.first.first);
        lastA = e.first.first+1;
        while (queries[i].first.first == lastA-1 && i < q){
            ans[queries[i].second] = query(queries[i].first.second);
            i++;
        }
        i--;
    }
 
 
    for (int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    
 
    return 0;
}
