#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    long long int ans = 0, n; cin >> n;
    unordered_map<string, int> retv;
    string str;
    for(long long int i = 0; i < n; ++i){
        cin >> str;
        ++retv[str];
        if (retv[str] == 2){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
