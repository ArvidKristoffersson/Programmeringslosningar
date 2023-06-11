#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    bool vaxel = true, neW = true;
    int n, m, change = 0; cin >> n >> m;
    vector<int> first, second;
    for (int i = n; i < 1440; i += n){
        first.push_back(i);
    }
    for (int i = m; i < 1440; i += m){
        second.push_back(i);
    }

    if(first[0] > second[0]){
        vaxel = false;
    }

    for (int i = 1; i < 1440; i++){
        if (count(all(first), i) == 1 && !vaxel){
            neW = true;
            change++;
        } else if (count(all(second), i) == 1 && vaxel){
            neW = false;
            change++;
        }

        vaxel = neW;
    }

    cout << change << endl;


    return 0;
}
