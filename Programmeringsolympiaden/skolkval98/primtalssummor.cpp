#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

bool isDistinct(vector<int> vec){
    vector<char> m;
    for (int i = 0; i < vec.size(); i++){
        string num = to_string(vec[i]);
        if (count(all(m), num[0])){
            return false;
        } else {
            m.push_back(num[0]);
        }

        if (count(all(m), num[1])){
            return false;
        } else {
            m.push_back(num[1]);
        }

        if (count(all(m), num[2])){
            return false;
        } else {
            m.push_back(num[2]);
        }

    }

    return true;

}

vector<int> distinctSubsets(int a, vector<int> primers){
    vector<int> distSub;
    for (int i = 0; i < a; i++){
        vector<int> tV = {};
        for (int j = i + 1; j < a; j++){
            for (int k = j + 1; k < a; k++){
                tV = {primers[i], primers[j], primers[k]};
                int tI = primers[i] + primers[j] + primers[k];
                if(isDistinct(tV))distSub.push_back(tI);
            }
        }
    }

    return distSub;
}

char zero = '0';

vector<int> allPrime(int a, int b){
        vector<int> primeNumbers;
        for (int i = a; i <= b; i++) {
            if (i == 1 || i == 0)
                continue;
            int flag = 1;
            for (int j = 2; j <= i / 2; ++j) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            string aj = to_string(i);
            if (flag == 1 && count(all(aj), zero) == 0)
                primeNumbers.push_back(i);
        }

        return primeNumbers;

}

int main(){
    vector<int> v = allPrime(99, 1000);
    vector<int> q = distinctSubsets(v.size(), v);

    sort(all(q));


    cout << q.size() << " " << q[0] << " " << q[q.size()-1] << endl;


    return 0;
}
