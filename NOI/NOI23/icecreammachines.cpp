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
queue<int> nextu[MAXN];
bool hasMachine[MAXN];
priority_queue<pair<int, int> > pq;

int main(){
    scoobydoobydoo();
    int n, c, k; cin >> n >> c >> k;

    vector<int> v(n); 
    for (int i = 0; i < n; i++){
        cin >> v[i];
        nextu[v[i]].push(i);
    }

    


    for (int i = 1; i <= c; i++){
        nextu[i].push((int)2e5);
    }

    int ans = 0;

    for (int i = 0; i < k; i++){
        pq.push({2e5, 0});
    }

    for (int i = 0; i < n; i++){
        if (hasMachine[v[i]]){
            nextu[v[i]].pop();
            pq.push({nextu[v[i]].front(), v[i]});
            continue;
        }

        int e = pq.top().second;
        pq.pop();
        hasMachine[e] = false;
        hasMachine[v[i]] = true;
        ans++;
        nextu[v[i]].pop();
        pq.push({nextu[v[i]].front(), v[i]});
    }

    cout << ans << endl;

    
    return 0;
}
