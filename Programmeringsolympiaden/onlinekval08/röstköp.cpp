#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int input, karl, tempNum;
    vector<int> all;


    cin >> input;
    cin >> karl;

    for (int i = 0; i < input - 1; i++){
        cin >> tempNum;
        all.push_back(tempNum);
    }

    int newKarl = karl;

    sort(all.rbegin(), all.rend());

    for (int j = 0; j < all.size(); j++){
        tempNum = all[j];
    }

    while (all[0] >= newKarl){
        newKarl++;
        all[0]--;

        sort(all.rbegin(), all.rend());
    }

    int votesBought = newKarl - karl;

    cout << votesBought << endl;

    return 0;
}
