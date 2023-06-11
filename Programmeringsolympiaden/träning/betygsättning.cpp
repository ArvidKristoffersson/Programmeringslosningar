#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    vector<int> v;
    vector<int>::iterator upper1;
    for (int i = 0; i < 5; i++){
        int tI; cin >> tI; v.push_back(tI);
    }
    int a; cin >> a;

    sort(all(v));

    upper1 = upper_bound(all(v), a);

    int upper = upper1 - v.begin() - 1;


    if (upper == -1){
        cout << 'F' << endl;
    } else if (upper == 0){
        cout << 'E' << endl;
    } else if (upper == 1){
        cout << 'D' << endl;
    } else if (upper == 2){
        cout << 'C' << endl;
    } else if (upper == 3){
        cout << 'B' << endl;
    } else if (upper == 4){
        cout << 'A' << endl;
    }




    return 0;
}
