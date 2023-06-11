#include <iostream>
#include <string>

using namespace std; 

string alph = "abcdefghijklmnopqrstuvwxyz";

int indAlph(char c){
    for (int i = 0; i < alph.size(); i++){
        if (alph[i] == c){
            return i;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;

    if (n == 1){
        string s = "", str;
        cin >> str;
        int a;
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                a = stoi(str);
                s = "";
            } else {
                s += str[i];
            }
        }

        for (int i = 0; i < s.size(); i++){
            int it = indAlph(s[i]);
            s[i] = alph[(it+a < alph.size() ? it+a : it+a-alph.size())];            
        }

        cout << s << endl;
        return 0;

    }

    cout << "abcdefghijklmnopqrstuvwxyz" << endl;




    return 0;
}
