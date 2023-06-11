#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

int main(){
    string s = "";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            char c; cin >> c;
            s += c;
        }
    }
    string solved = "123456780";

    queue<pair<string, string> > q;
    q.push({s, s});
    bool done = false;

    map<string, int> m;
    m[s] = 0;

    while (!q.empty() && !done){
        string s = q.front().first;
        string parent = q.front().second;
        q.pop();
        for (int i = 0; i < 9; i++){
            if (s[i] == '0' && (m.find(s) == m.end() || m[s] == 0)){
                if(s == solved){
                    cout << m[parent] << endl;
                    return 0;
                }
                string p = s;
                if (i > 2){
                    swap(p[i], p[i-3]);
                    q.push({p, s});
                }
                p = s;
                if (i < 6){
                    swap(p[i], p[i+3]);
                    q.push({p, s});
                }
                p = s;
                if (i%3 < 2){
                    swap(p[i], p[i+1]);
                    q.push({p, s});
                }
                p = s;
                if (i%3 > 0){
                    swap(p[i], p[i-1]);
                    q.push({p, s});
                }
                m[s] = m[parent]+1;
            }
        }
    }
        



    return 0;
}
