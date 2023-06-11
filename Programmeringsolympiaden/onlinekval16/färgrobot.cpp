#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int main(){
    int n; cin >> n;
    string str, ans = ""; cin >> str;
    vector<char> c;
    int i = 0, j = 0, k = 0;
    while(k < n && i < str.size() && j < str.size()){
        if (count(all(c), str[j]) == 0){
            c.push_back(str[j]);
            //cout << 1 << endl;
        } 
        if (c.size() == 3){
            //cout << 2 << endl;
            i = j;
            c.clear();
            k++;
            ans += str[i];
        }
        j++;
    }

    cout << ans << endl;

    return 0;
}
