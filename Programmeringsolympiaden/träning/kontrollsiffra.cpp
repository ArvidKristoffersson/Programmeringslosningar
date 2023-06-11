#include <iostream>

using namespace std;

int main(){
    long long int summa = 0;

    for (int i = 1; i < 10; i++){
        int inp; cin >> inp;
        if(i%2==1){
            summa += 3*inp;
        } else {
            summa += 7*inp;
        }
    }



    cout << summa%10 << endl;


    return 0;

}

