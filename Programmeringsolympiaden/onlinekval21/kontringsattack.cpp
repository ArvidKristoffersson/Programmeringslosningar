#include <iostream>
#include <map>

using namespace std; 

int main(){
    int n, a, b, q = -1, k = 0, quq = -1; cin >> n;
    map<int, int> m;
    
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        int c = 0;
        if (a < b){
            c = 1;
        } else if (a > b){
            c = -1;
        }
        m[abs(a-b)] += c;
        quq = max(abs(a-b), quq);
    }

    int ans = 0, tot = 0;

    for (int i = 1; i <= quq; i++){
        tot += m[i];
        if (ans < tot){
            k = i;
            ans = tot;
        }
    }

    cout << k << endl;

    

    return 0;
}
