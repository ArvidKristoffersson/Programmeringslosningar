#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

vector<int> allTriangles(int maximus){
    vector<int> triangleZZ;
    int ans = 0;
    for (int i = 0; ans <= maximus; i++){
        ans += i;
        triangleZZ.push_back(ans);
    }

    return triangleZZ;

}

int  main(){
    vector<int> prefixSum = {0};
    int x; cin >> x;
    vector<int> v = allTriangles(x);
    for (int i = 1; i < v.size(); i++){
        prefixSum.push_back(prefixSum[i-1] + v[i]);
        //cout << prefixSum[i] << endl;
    }
    int i = 0, j = 1;

    while (i < j ){
        int sum = prefixSum[j] - prefixSum[i];
        if (sum == x){
            cout << i + 1 << " " << j << endl;
            return 0;
        }
        if (sum > x){
            i++;
        } else {
            j++;
        }

    }


    cout << "NEJ" << endl;





    return 0;
}
