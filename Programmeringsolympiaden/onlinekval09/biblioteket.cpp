#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define all(x)  (x).rbegin(), (x).rend()

using namespace std; 

int main(){
    int n, k, t; cin >> n >> k;
    vector<int> over, under;

    for (int i = 0; i < n; i++){
        cin >> t;
        if (t > 0){
            over.push_back(t);
        } else {
            under.push_back(abs(t));
        }
    }

    sort(all(over));
    sort(all(under));

    int maxi = max(over[0], under[0]);

    int tot = 0;

    for (int i = 0; i < over.size(); i += k){
        tot += over[i]*2;
    }
    for (int i = 0; i < under.size(); i += k){
        tot += under[i]*2;
    }

    tot -= maxi;

    cout << tot << endl;

    
    return 0;
}
