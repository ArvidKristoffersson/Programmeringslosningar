#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define all(x)  (x).begin(), (x).end()

typedef long long ll;

using namespace std;

int main(){
    string str; cin >> str;
    int k; cin >> k;

    for (int i = 0; i < str.size()-1 && k >= 0; i++){
        ll minimus = 1e9+1;
        int x = 0;
        for (int j = i; j < str.size() && j-i <= k; j++){
            char c = str[j];
            if (int(c) < minimus){
                minimus = int(c);
                x = j;
            }
        }

        for (int j = x; j > i; j--){
            swap(str[j], str[j-1]);
        }
        k -= x-i;
    }

    cout << str << endl;

    return 0;
}
