#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int weeks, tempNum, misNum = 0, empNum = 0;
    vector<int> pres, mis, emp;

    cin >> weeks;

    for (int i = 0; i < weeks; i++){
        cin >> tempNum;
        pres.push_back(tempNum);
    }

    for(int j = 1; j < pres.size(); j++){
        tempNum = pres[j] - pres[j - 1];
        if (tempNum > 0){
            mis.push_back(tempNum);
        }
        if (tempNum < 0){
            emp.push_back(abs(tempNum));
        }
    }

    for(int k = 0; k < mis.size(); k++){
        misNum += mis[k];
    }
    for(int l = 0; l < emp.size(); l++){
        empNum += emp[l];
    }

    cout << empNum << " " << misNum << endl;

    return 0;
}
