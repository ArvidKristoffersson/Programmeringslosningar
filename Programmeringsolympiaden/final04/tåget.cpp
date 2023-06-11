#include <iostream>
#include <iomanip>

using namespace std; 

long double fakultet(long double x){
    if (x == 1){
        return x;
    }

    return x * fakultet(x-1);
}

long double nChooseK(long double n, long double k){
    if (n == k){
        return 1;
    }
    return (fakultet(n)/(fakultet(k)*fakultet(n-k)));
}

int main(){ 
    int q; cin >> q;

    long long int ans = 0;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (i+j >= q)continue;
            long double a = q - i - j - 2;
            long double b = 1;

            while (a >= b){
                ans += nChooseK(a, b);
                a--;
                b++;
            }
            ans++;

        }
    }

    cout << fixed << setprecision(0);


    cout << ans << endl;

    return 0;
}
