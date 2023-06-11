#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n, c; cin >> n >> c;
    int pas = 0, wait = 0;
    map<int,int> m;

    for (int i = 0; i < n-1; i++){
        m[i] = 0;
    }

    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        pas -= m[i];
        for (int j = 0; j < x; j++){
            int val; cin >> val;
            if (pas < c){
                m[val-1]++;
                pas++;
            } else {
                wait++;
            }
        }
    }

    cout << wait << endl;

    return 0;
}
