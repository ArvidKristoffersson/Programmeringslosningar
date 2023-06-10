#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)   (x).begin(), (x).end()

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> needs, have;

    for (int i = 0; i < n; i++){
        int tI; cin >> tI;
        needs.push_back(tI);
    }

    for (int i = 0; i < m; i++){
        int tI; cin >> tI;
        if (count(all(needs), tI)){
            auto it = find(all(needs), tI) - needs.begin();
            needs.erase(needs.begin()+it);
        } else {
            have.push_back(tI);
        }
    }

    sort(all(needs));
    sort(all(have));

    int i = have.size()-1;

    while (have.size() > 0){
        int i = have.size()-1;
        for (int j = needs.size()-1; j > -1; j--){
            if (have[i] > needs[j]){
                needs.erase(needs.begin() + j);
                have.erase(have.end()-1);
                break;
            }
        }
        if (i == have.size()-1){
            have.erase(have.end()-1);
        }
    }

    cout << needs.size() << endl;

    for (int i = 0; i < needs.size(); i++){
        cout << needs[i] << " ";
    }


    return 0;
}
