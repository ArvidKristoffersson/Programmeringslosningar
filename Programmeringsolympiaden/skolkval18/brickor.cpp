#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std; 

pair<string, string> moveMake(string str, int x, int y){
    string q = "";
    if (str[x] == 'S'){
        q += 'V';
    } else {
        q += 'S';
    }
    if (str[y] == 'S'){
        q += 'V';
    } else {
        q += 'S';
    }

    string w = q, r = "";

    for (int i = 0; i < str.size(); i++){
        if (i != x && i != y){
            w += str[i];
            r += str[i];
        }
    }
    r += q;

    return {w, r};

}


int main(){
    string str, solved = ""; cin >> str;

    for (int i = 0; i < str.size(); i++){
        solved += 'V';
    }

    int len = str.size();

    map<string, int> m;
    m[str] = 0;
    queue<pair<string, string> > q;
    q.push({str, str});

    while (!q.empty()){
        string s = q.front().first, parent = q.front().second;
        q.pop();
        if (m.find(s) == m.end() || m[s] == 0){
            for (int i = 0; i < len; i++){
                if (s == solved){
                    cout << m[parent] << endl;
                    return 0;
                }
                if (s[i] == 'S' && i + 1 != len){
                    pair<string, string> z = moveMake(s, i, i+1);
                    //cout << s << endl;
                    q.push({z.first, s});
                    q.push({z.second, s});
                }
                if (s[i] == 'S' && s[i-1] == 'V'){
                    pair<string, string> z = moveMake(s, i-1, i);
                    q.push({z.first, s});
                    q.push({z.second, s});
                }
            }
            m[s] = m[parent] + 1;
        }
    }

    cout << 1 << endl;


    return 0;
}
