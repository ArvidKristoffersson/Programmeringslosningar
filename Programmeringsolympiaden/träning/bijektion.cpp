#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> x, y;
    for (int i = 1; i < m+1; i++){
        y.push_back(i);
    }
    for (int i = 0; i < n; i++){
        int tI; cin >> tI;
        x.push_back(tI);
    }

    sort(all(x));
    sort(all(y));
    

    if (x == y){
        cout << "Bijektion" << endl;
    } else {
        cout << "Nope" << endl;
    }




    return 0;
}
