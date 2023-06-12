#include <iostream>
#include <vector>

using namespace std; 

vector<int> q;

int main(){
    int m, n, ans = 0, x; cin >> m >> n;
    q.push_back(0);
    for (int i = 0; i < n; i++){
        int tI; cin >> tI;
        q.push_back(--tI);
    }

    for (int i = 0; i < n; i++){
        x = abs(q[i] - q[i+1]);
        ans += min(x, m-x);
    }

    cout << ans << endl;

    return 0;
}
