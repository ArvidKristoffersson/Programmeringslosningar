#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, n; cin >> t >> n;
    t *= 60;
    vector<int> v;
    
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    
    int count = 0;
    int ans = 0;
    
    while (count < v.size()){
        if (t - v[count] < 0){
            cout << ans << endl;
            return 0;
        }

        t -= v[count];
        ans += v[count];
        count++;
    }
    cout << ans << endl;
    
    
    return 0;
}
