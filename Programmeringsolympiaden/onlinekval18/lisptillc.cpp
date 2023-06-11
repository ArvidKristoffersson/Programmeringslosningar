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
    string inp; getline(cin, inp);

    string namn = "";

    for (int i = 0; i < inp.size(); i++){
        if (inp[i] == '('){
            string t = "";
            int j = i+1;
            for(j = i+1; inp[j] != ' ' && inp[j] != ')' && j < inp.size(); j++){
                t += inp[j];
            }
            namn += t;
            i = j-1;
            namn += '(';
            //cout << ": " << namn << endl;
        } else {
            namn += inp[i];
        }
        
    }

    string ans = "";

    for (int i = 0; i < namn.size(); i++){
        ans += namn[i];
        if (namn[i] != ' ' && namn[i] != '(' && namn[i+1] == ' '){
            ans += ',';
        } else if (namn[i] == '(' && namn[i+1] == ' '){
            i++;
        }
    }


    cout << ans << endl;


    //Ta ut namnet
    //Ta bort tomrummet mellan öppningsparantes och första variabeln
    //Sätta in kommatecken mellan variabler.




    return 0;
}
