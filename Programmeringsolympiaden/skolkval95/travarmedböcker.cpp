#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    int x; cin >> x;
    vector<int> v;
    vector<vector<int> > already;
    for(int i = 0; i < x; i++){
        int c; cin >> c;
        v.push_back(c);
    }

    while (count(all(already), v) < 2){
        int it = -1, add = v.size();
        for(int i = 0; i < v.size(); i++){
            v[i]--;
        }
        int amountZ = count(all(v), 0);
        for (int i = 0; i < amountZ; i++){
            it = find(all(v), 0) - v.begin();
            v.erase(v.begin() + it);
        }

        v.push_back(add);
        for (int i = 0; i < v.size(); i++){
        }

        already.push_back(v);
    }

    already.pop_back();

    int it = find(all(already), v) - already.begin();

    cout << it + 2 << " " << already.size() + 2 << endl;

    return 0;
}
