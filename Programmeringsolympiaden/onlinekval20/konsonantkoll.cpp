#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> cons = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z"};



int main(){
    string input, output, tS;
    int counter;
    vector<string> v;

    getline(cin, input);

    for (int j = 0; j < input.size(); j++){
        tS = input[j];
        v.push_back(tS);
    }


    for (int i = 0; i < v.size(); i++){

        if (count(cons.begin(), cons.end(), v[i]) && v[i] == v[i - 1] && v[i] == v[i - 2]){
        } else {
            output += v[i];
        }

    }


    cout << output << endl;

    return 0;
}
