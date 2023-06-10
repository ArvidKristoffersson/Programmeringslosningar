#include <iostream>
#include <cmath>

using namespace std;

void testCase1(long double a, long double q){
    long double b = 1;
    long double n = pow(a, 0.5);

    long long maximusSoFarus = 1e12;

    long long ans1, ans2;

    while (b <= n){
        long double l = q/b;
        if (l == floor(l) && abs(l-b) < maximusSoFarus){
            maximusSoFarus = abs(l-b);
            ans1 = l;
            ans2 = b;
        }
        b++;

    }


    cout << ans2 << " " << ans1 << endl;

    return;
}

int main(){
    long double a, b; cin >> a >> b;

    if (a == b){
        testCase1(a, b);
        return 0;
    }

    long double i = floor(pow(b, 0.5));
    long double j = i;

    while (i*j < a || i*j > b){
        if (i*j < a && j <= b)j++;
        if (i*j > b && i > 1)i--;
    }

    cout << i << " " << j << endl;



    return 0;
}
