#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int bSum = 0, tempNum = 0, var;
    string input, oldS, newS;

    cin >> input;

    int strSize = input.size()/2;


    for (int j  = strSize - 1; j > -1; j--){
        newS = input[j];
        if (newS == "B"){
                bSum++;
        }
    }

    tempNum = bSum;
    for (int i = strSize; i < input.size() + strSize - 1; i++){
        if (i >= input.size()){
            newS = input[i - input.size()];
        } else {
            newS = input[i];
        }

        oldS = input[i - strSize];

        if (oldS == "B"){
            tempNum--;
        }
        if (newS == "B"){
            tempNum++;
        }



        if(tempNum > bSum){
            bSum = tempNum;
        }

    }

    cout << bSum << endl;

    return 0;
}
