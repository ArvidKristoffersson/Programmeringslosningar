#include <iostream>
#include <vector>

using namespace std;

int main(){
    int input, tI, parSum = 0, slagSum = 0;

    cin >> input;

    for (int i = 2; i < input + 2; i++){
        if (i%2 == 0){
            parSum += 2;
        } else {
            parSum += 3;
        }
        cin >> tI;
        if (tI > 7){
            tI = 7;
        }
        slagSum += tI;
    }

    cout << slagSum - parSum << endl;

    return 0;
}
