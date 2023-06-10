#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 


const int MAXN = 1e5+1;
int arr[MAXN][3];
long double ans = 1e9;

long double f(double x, double a, double b, double c){
    return -(a*(pow(x, 2)) + b*x + c);
}

long double ternary(double left, double right, double absolute_precision, double a, double b, double c){
    if (abs(right - left) < absolute_precision){
        return f((left + right)/2, a, b, c);
    }
    double leftThird = (2*left + right)/3;
    double rightThird = (2*right + left)/3;

    if (f(leftThird, a, b, c) > f(rightThird, a, b, c)){
        return ternary(leftThird, right, absolute_precision, a, b, c);
    } else {
        return ternary(left, rightThird, absolute_precision, a, b, c);
    }
}

int main(){
    int n; cin >> n;
    long int q = 0, w = 0, e = 0;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++){
        int x, y, z, t; cin >> x >> y >> z >> t;
        v.push_back({t, i});
        arr[i][0] = x;
        q += x;
        arr[i][1] = y;
        w += y;
        arr[i][2] = z;
        e += z;
    }

    sort(all(v));

    for (int i = 0; i < v.size(); i++){
        ans = min(ans, ternary(0, v[i].first, 1e-6, q, w, e));
        int c = v[i].second;
        q -= arr[c][0];
        w -= arr[c][1];
        e -= arr[c][2];
    }



    cout << ans * -1 << endl;



    return 0;
}
