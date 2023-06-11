#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ordAn;

void rec(vector<int> v, int index, int ord){
    ordAn = (ord-1+index)%v.size();

    if (v.size() == 1){
        cout << v[0] + 1 << endl;
    } else {
        v.erase(v.begin() + ordAn);

        rec(v, ordAn, ord);
    }

}




int main(){
    int ord, barn;
    vector<int> v;

    cin >> ord >> barn;


    for (int i = 0; i < barn; i++){
        v.push_back(i);
    }


    rec(v, 0, ord);

    return 0;
}
