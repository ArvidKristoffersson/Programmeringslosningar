#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

int main(){
    int a, b ,c; 
    cin >> a >> b >> c; 
    vector<int> s;
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
    sort(all(s));
    for (int i = 0; i < 3; i++){
        cout << s[i] << " ";
    }


    return 0;
}
