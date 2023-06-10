//27 poäng xD
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <time.h>

#pragma GCC optimize("Ofast,inline") 
#pragma GCC optimize ("unroll-loops")

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAXN = 2e3+1;
char arr[MAXN][MAXN];

int main(){
    scoobydoobydoo();
    int t; cin >> t;
    if (t == 1 || t == 4 || t == 8 || t == 9){
        srand(1);
    } else if (t == 6){
        srand(2);
    } else if (t == 3){
        srand(6);
    } else if (t == 5 || t == 2){
        srand(4);
    } else if (t == 7 || t == 10){
        srand(3);
    }
    int r, c, n; cin >> r >> c >> n;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    string str = "<>^v";
    string output = "";
    for (int i = 0; i < n; i++){
        int randIn = rand()%4;
        output += str[randIn];
    }

    cout << output << endl;

    
    



    return 0;
}
