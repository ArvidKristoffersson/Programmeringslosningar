#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;


int main(){
    int n; cin >> n;
    vector<string> names, dates, apN, apD;
    vector<int> arr;

    for (int i = 0; i < n; i++){
        string tI, tI2; int like; cin >> tI >> like >> tI2;
        names.push_back(tI);
        dates.push_back(tI2);
        arr.push_back(like);
    }

    vector<int> v = arr;

    sort(all(arr));

    for (int i = arr.size() - 1; i > -1; i--){
        int it = find(all(v), arr[i]) - v.begin();
        if (count(all(apD), dates[it]) == 0){
            apN.push_back(names[it]);
            apD.push_back(dates[it]);
        }
    }

    sort(all(apN));

    cout << apN.size() << endl;

    for (int i = 0; i < apN.size(); i++){
        cout << apN[i] << endl;
    }

    return 0;
}
