#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x; cin >> x;
    double myrben = 168 - x/2;
    if (myrben != floor(myrben) || myrben > 42 || myrben < 0){
        cout << "FEL" << endl;
    } else {
        cout << myrben << endl;
    }

    return 0;
}
