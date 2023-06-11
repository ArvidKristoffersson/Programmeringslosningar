#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int pa, ka, pb, kb, n, a, b; cin >> pa >> ka >> pb >> kb >> n;
    long long int minimus = 100000000000;

    for (int i = 0; i <= ceil(n/ka); i++){
        for (int j = 0; j <= ceil(n/kb); j++){
            long long int m = ka * i + kb * j;
            if (m >= n){
                long long int mini = pa * i + pb * j;
                if (mini < minimus){
                    a = i;
                    b = j;
                    minimus = mini;
                }
            }
        }

    }

    cout << a << " " << b << " " << minimus << endl;


    return 0;
}
