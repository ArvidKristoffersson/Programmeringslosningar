#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<int> input;

int bubbleSort(int q){
    int ans = 0; 
    for (int i = 0; i < q - 1; i++){
        for (int j = 0; j < q - i - 1; j++){
            if(input[j] > input[j+1]){
                swap(input[j], input[j+1]);
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    int q; cin >> q; 
    for (int i = 0; i < q; i++){
        int tI; cin >> tI;
        input.push_back(tI);
    }

    cout << bubbleSort(q) << endl;


    return 0;
}
