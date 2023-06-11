#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    long long int n, t, ans = 0; cin >> n >> t;
    vector<long long int> dist;

    for (int i = 0; i < n; i++){
        long long int x, y;
        cin >> x >> y;
        dist.push_back((abs(x)+abs(y))*2);
    }

    sort(dist.begin(), dist.end());

    long long int tid = 0;

    for (int i = 0; i < dist.size(); i++){
        if (tid + dist[i] > t){
            cout << ans << endl;
            return 0;
        }
        ans++;
        tid += dist[i];
    }


    cout << ans << endl;





    return 0;
}
