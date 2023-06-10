#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;



inline void scoobydoobydoo()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}


int main(){
    scoobydoobydoo();
    map<char, string> m;
    map<string, char> conversion;
    vector<char> v;
    for (int i = 0; i < 26; i++){
        char t; cin >> t;
        v.push_back(t);
        string s; cin >> s;
        m[t] = s;
        conversion[s] = t;
    }
    conversion["yo"] = ' ';

    ll S, P; cin >> S >> P;
    ll T, B, M; cin >> T >> B >> M;

    int rand; cin >> rand;
    string text; cin >> text;

    ll zC = 0;

    string cur = "", ret = "";

    vector<string> vec;

    ll lastOc;


    for (int i = 0; i < text.size(); i++){
        ll oC = 0;
        int j = i;
    
        while(text[j] == '1'){
            oC++;
            j++;
        }
        int q = j;
        ll zC = 0;
        while (text[q] == '0' && q < text.size()){
            zC++;
            q++;
        }
        if (oC == P){
            cur += '.';
        } else {
            cur += '-';
        } 

        if (zC == B){
            vec.push_back(cur);
            cur.clear();
        } else if (zC == M){
            vec.push_back(cur);
            vec.push_back("yo");
            cur.clear();
        }

        lastOc = oC;

        i = q-1; 

    }
    vec.push_back(cur);


    for (auto e : vec){ 
        cout << conversion[e];
    }
    cout << endl;






    return 0;
}
