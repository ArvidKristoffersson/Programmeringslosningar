#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    int n; cin >> n;
    vector<double> v;
    vector<double> limit;
    string str = "0123456789abcdef";
    string ans = "";


    for (int i = 0; i < n; i++){
        double x; cin >> x;
        v.push_back(x);
        //cout << "          " << i << ".:^^ " << endl;
    }

    for (double i = 0; i < 16; i++){
        limit.push_back(i * 225);
        //cout << " : " << i * 225 << endl;
    }

    double ascii = 0;
    int q = 1;

    for (int i = 0; i < v.size(); i++){
        double upper = upper_bound(all(limit), v[i] * 10) - limit.begin() - 1;
        if (floor(upper / 10) != 0){
            ascii += upper;
        } else {
            ascii += upper * pow(16, q);
        }
        q--;
        //cout << upper << " " << i << ": " << ascii << endl;
        if (q == -1){
            char inp = ascii;
            ans += inp;
            ascii = 0;
            q = 1;
        }



    }

    cout << ans << endl;



    return 0;
}
