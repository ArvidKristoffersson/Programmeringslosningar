#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> kanin;

bool possible(int a, int b, int c){
    vector<int> vec = kanin,  temp;
    vector<int> outcome = kanin;
    sort(outcome.rbegin(), outcome.rend());
    for (int i = 0; i < a; i++){
        temp.push_back(vec[i]);
    }
    vec.erase(vec.begin(), vec.begin() + a);
    for (int i = temp.size()-1; i > -1; i--){
        vec.push_back(temp[i]);
    }

    temp.clear();

    for (int i = 0; i < b; i++){
        temp.push_back(vec[i]);
    }
    vec.erase(vec.begin(), vec.begin() + b);
    for (int i = temp.size()-1; i > -1; i--){
        vec.push_back(temp[i]);
    }
    
    temp.clear();

    for (int i = 0; i < c; i++){
        temp.push_back(vec[i]);
    }
    vec.erase(vec.begin(), vec.begin() + c);
    for (int i = temp.size()-1; i > -1; i--){
        vec.push_back(temp[i]);
    }

    if(vec == outcome)return true;

    return false;
}



int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        kanin.push_back(t);
    }

    

    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            for (int k = 1; k < n+1; k++){
                if (possible(i, j, k)){
                    cout << k << " " << j << " " << i << endl;
                    return 0;
                }
            }
        }
    }
    


    return 0;
}
