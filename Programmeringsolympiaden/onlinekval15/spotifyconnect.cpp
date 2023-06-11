#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

#define all(x)  (x).begin(), (x).end()

using namespace std; 

int main(){
    vector<pair<int, string> > v;
    int n, p; cin >> n;
    string t, q; 

    for (int i = 0; i < n; i++){
        cin >> p >> t >> q;
        if (t == "mobile")p += 100;
        v.push_back({p, q});
    }

    int musik = 0;

    sort(all(v));

    string com, prevCom = "paus";
    int c, prevC = -1;

    for (int i = 0; i < v.size(); i++){
        c = v[i].first;
        com = v[i].second;
        
        if (prevCom == "play" && com == "paus"){
            musik += c - prevC;
            prevC = -1;
        }

        if (com == "play" && prevC == -1)prevC = c;

        prevCom = com;
    }

    cout << musik << endl;



    return 0;
}
