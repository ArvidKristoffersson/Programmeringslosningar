#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

string start, ending; 
vector<string> possibilities = {"AAA", "AAB", "AAC", "ABA", "ABB", "ABC", "ACA", "ACB", "ACC", 
                                "BAA", "BAB", "BAC", "BBA", "BBB", "BBC", "BCA", "BCB", "BCC", 
                                "CAA", "CAB", "CAC", "CBA", "CBB", "CBC", "CCA", "CCB", "CCC",
                                "AA", "AB", "AC", "BA", "BB", "BC", "CA", "CB", "CC", "A", "B", "C"};


vector<pair<string, string>> generateMoves(char whereLeft, string now){
    vector<pair<string, string> > v;
    for (string s : possibilities){
        string temp = "";
        for (int j = 0; j < now.size(); j++){
            if (now[j] == whereLeft){
                temp += s;
            } else {
                temp += now[j];
            }
        }
        if (temp.size() <= ending.size())v.push_back({temp, s});
    }
    
    return v;
}

int main(){
    scoobydoobydoo();
    unordered_map<string, bool> uM;
    cin >> start >> ending;
    queue<pair<string, pair<int, vector<pair<char, string> > > > > q;
    uM[start] = true;
    q.push({start, {3, {}}});
    string whereLeft = "ABC";

    while (!q.empty()){
        string s = q.front().first;
        int left = q.front().second.first;
        vector<pair<char, string> > moves = q.front().second.second;
        q.pop();
        uM[s] = true;

        if (s == ending){
            for (auto e : moves){
                cout << e.first << " " << e.second << endl;
            }
            return 0;
        } else if (left == 0){
            continue;
        }

        for (int i = 0; i < whereLeft.size(); i++){
            vector<pair<string, string>> t = generateMoves(whereLeft[i], s);

            for (auto l : t){
                if (uM[l.first])continue;
                vector<pair<char, string> > g = moves;
                g.push_back({whereLeft[i], l.second});
                q.push({l.first, {left-1, g}});
            }
        }
    }

    cout << "failed" << endl;





    return 0;
}
