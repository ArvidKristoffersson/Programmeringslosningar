#include <iostream>

using namespace std;

int main(){
    double a, b, c; cin >> a >> b >> c;
    double sum = a * c - b;

    if (sum < 0){
        cout << "Spela" << endl;
    } else {
        cout << "Spela inte!" << endl;
    }



    return 0;
}
