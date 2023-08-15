#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define all(x)  (x).begin(), (x).end()

typedef long long ll;

using namespace std;

int main(){
    int n; cin >> n;
    map<vector<pair<char, char> >, int> M;
    map<int, vector<pair<char, char> > > K;

    M[{{'*', '.'}, {'.', '.'}, {'.', '.'}}] = 1;

    M[{{'*', '.'}, {'*', '.'}, {'.', '.'}}] = 2;

    M[{{'*', '*'}, {'.', '.'}, {'.', '.'}}] = 3;

    M[{{'*', '*'}, {'.', '*'}, {'.', '.'}}] = 4;

    M[{{'*', '.'}, {'.', '*'}, {'.', '.'}}] = 5;

    M[{{'*', '*'}, {'*', '.'}, {'.', '.'}}] = 6;

    M[{{'*', '*'}, {'*', '*'}, {'.', '.'}}] = 7;

    M[{{'*', '.'}, {'*', '*'}, {'.', '.'}}] = 8;

    M[{{'.', '*'}, {'*', '.'}, {'.', '.'}}] = 9;

    M[{{'.', '*'}, {'*', '*'}, {'.', '.'}}] = 0;


    K[1] = {{'*', '.'}, {'.', '.'}, {'.', '.'}};

    K[2] = {{'*', '.'}, {'*', '.'}, {'.', '.'}};

    K[3] = {{'*', '*'}, {'.', '.'}, {'.', '.'}};

    K[4] = {{'*', '*'}, {'.', '*'}, {'.', '.'}};

    K[5] = {{'*', '.'}, {'.', '*'}, {'.', '.'}};

    K[6] = {{'*', '*'}, {'*', '.'}, {'.', '.'}};

    K[7] = {{'*', '*'}, {'*', '*'}, {'.', '.'}};

    K[8] = {{'*', '.'}, {'*', '*'}, {'.', '.'}};

    K[9] = {{'.', '*'}, {'*', '.'}, {'.', '.'}};

    K[0] = {{'.', '*'}, {'*', '*'}, {'.', '.'}};

    vector<vector<pair<char, char>>> v(n);
    for (int j = 0; j < 3; j++){
       for (int i = 0; i < n; i++){
            char c, t; cin >> c >> t;
            v[i].push_back({c, t});
       } 
    }

    ll num1 = 0;
    int j = 1;
    for (int i = v.size()-1; i > -1; i--){
        num1 += M[v[i]]*j;
        j *= 10;
    }

    int m; cin >> m;

    vector<vector<pair<char, char>>> q(m);
    for (int j = 0; j < 3; j++){
       for (int i = 0; i < m; i++){
            char c, t; cin >> c >> t;
            q[i].push_back({c, t});
       } 
    }

    ll num2 = 0;
    j = 1;
    for (int i = q.size()-1; i > -1; i--){
        num2 += M[q[i]]*j;
        j *= 10;
    }



    vector<vector<pair<char, char>>> vec;

    ll g = num1 + num2;

    if (g == 0){
        vec.push_back(K[0]);
    }

    while (g){
        vec.push_back(K[g%10]);
        g /= 10;
    }

    for (int j = 0; j < 3; j++){
        for (int i = vec.size()-1; i > -1; i--){
            cout << vec[i][j].first << vec[i][j].second << " ";
        }
        cout << endl;
    }



    return 0;
}
