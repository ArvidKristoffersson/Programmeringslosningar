#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define all(x)  (x).begin(), (x).end()

using namespace std;
 
vector<int> a, b;
long long int minimus = 1e15;
bool done = false;

void binarySearch(double p){
    if (done)return;
    int x = 0, y = b.size()-1;
    while (x <= y){
        double q = x + y;
        int k = floor(q/2);
        minimus = min(minimus, (long long int) abs(p+b[k]*2));
        if (abs(p+b[k]*2) == 0){
            done = true;
            cout << k << endl;
            return;
        }
        if (p+b[k]*2 > 0)y = k-1;
        else x = k+1;
    }
}

int main(){
    int n; cin >> n;
    long long int prefix1 = 0;

    for (int i = 0; i < n; i++){
        int t; cin >> t;
        a.push_back(t);
        prefix1 += t;
    }
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        b.push_back(t);
        prefix1 -= t;
    }
    sort(all(b));
    sort(all(a));

    for (long long int e : a){
        binarySearch((double)(prefix1 - e*2));
    }


    cout << minimus << endl;



    return 0;
}
