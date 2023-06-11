#include <iostream>

using namespace std; 

int main(){
    double up = 1e9, down = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        double q, k; cin >> q >> k;
        up = min(up, (k+5)/q);
        down = max(down, (k-5)/q);
    }
    int t; cin >> t;
    double cost = t * ((up+down)/2);
    int a = (int) cost;
    if (a%10 >= 5){
        a += 10;
    }
    a -= a%10;


    cout << a << endl;



    return 0;
}
