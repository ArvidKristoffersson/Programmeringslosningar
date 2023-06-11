#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std; 

vector<pair<double, double> > v;

double f(double x){
    double sum = 0;
    for (auto e : v){
        double q = pow((e.first - x), 2) + pow(e.second, 2);
        sum += sqrt(q);
    }
    return sum;
}

double ternary(double left, double right, double absolute_precision){
    if (abs(right - left) < absolute_precision){
        return f((left + right)/2);
    }
    double leftThird = (2*left + right)/3;
    double rightThird = (2*right + left)/3;

    if (f(leftThird) > f(rightThird)){
        return ternary(leftThird, right, absolute_precision);
    } else {
        return ternary(left, rightThird, absolute_precision);
    }
}

int main(){
    int n; cin >> n;
    double mi = 1e9, ma = -1e9;
    for (int i = 0; i < n; i++){
        double a, b; cin >> a >> b;
        v.push_back({a, b});
        mi = min(mi, a);
        ma = max(ma, a);
    }

    cout << fixed << setprecision(5);
    cout << ternary(mi, ma, 1e-8) * 2 << endl;



    return 0;
}
