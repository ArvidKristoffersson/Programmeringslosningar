#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int input;
    cin >> input;
    int sum = 0;
    for (int i = 1; i <= input; i++){
        sum += pow(i, 3);
    }
    cout << sum;
    return 0;
}
