#include <iostream>
#include <cmath>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    double a, b, c, d, ans = 0; cin >> a >> b >> c >> d;
    ans += d + c;
    a -= c;

    while (b > 0){
        if(floor(b/2)){
            ans += floor(b/2);
            b -= floor(b/2)*2;
        } else {
            ans++;
            a -= 2;
            b = 0;
        }
    }

    while (a > 0){
        ans++;
        a -= 4;
    }

    cout << ans << endl;


    return 0;
}
