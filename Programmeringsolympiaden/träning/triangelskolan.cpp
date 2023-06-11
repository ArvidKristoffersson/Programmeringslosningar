#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

vector<int> allTriangles(int maximus){
    vector<int> triangleZZ;
    int ans = 0;
    for (int i = 1; ans <= maximus; i++){
        ans += i;
        triangleZZ.push_back(ans);
    }

    return triangleZZ;

}

int  main(){
    int x; cin >> x;
    vector<int> v = allTriangles(x);
    int upper = upper_bound(all(v), x) - v.begin();

    cout << upper << endl;




    return 0;
}
