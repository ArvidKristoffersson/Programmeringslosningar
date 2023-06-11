#include <iostream>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;

ll linf = 1e15+1;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int sturt(char e){
    int ret = 2;
    if (e - '0' > 1){
        ret = 3;
    }
    if (e - '0' > 2){
        ret = 4;
    }
    if (e - '0' > 3){
        ret = 5;
    }
    if (e - '0' > 4){
        ret = 6;
    }
    if (e - '0' > 5){
        ret = 7;
    }
    if (e - '0' > 6){
        ret = 8;
    }
    if (e - '0' > 7){
        ret = 9;
    }
    if (e - '0' > 8){
        ret = 10;
    }
    if (e == 'A'){
        ret = 11;
    } else if (e == 'B'){
        ret = 12;
    } else if (e == 'C'){
        ret = 13;
    } else if (e == 'D'){
        ret = 14;
    } else if (e == 'E'){
        ret = 15;
    } else if (e == 'F'){
        ret = 16;
    }
    return ret;
}

int startingPoint(string a, string b, string s){




    int ret = 2;
    for (auto e : a){
        ret = max(ret, sturt(e));
    }
    for (auto e : b){
        ret = max(ret, sturt(e));
    }
    for (auto e : s){
        ret = max(ret, sturt(e));
    }
    return ret;
}

int retVal(char c){
    if (c - '0' < 10){
        return (c-'0');
    } else if (c == 'A'){
        return 10;
    } else if (c == 'B'){
        return 11;
    } else if (c == 'C'){
        return 12;
    } else if (c == 'D'){
        return 13;
    } else if (c == 'E'){
        return 14;
    }
    return 15;
}

bool isAdd(string a, string b, string s, int bas){
    if (bas < 11){
        int sum = 0;
        int count = 0;
        for (int i = a.size()-1; i >= 0; i--){
            char e = a[i];
            sum += (e - '0')*(pow(bas, count));
            count++;
        }
        count = 0;
        for (int i = b.size()-1; i >= 0; i--){
            char e = b[i];
            sum += (e - '0')*(pow(bas, count));
            count++;
        }
        count = 0;
        for (int i = s.size()-1; i >= 0; i--){
            char e = s[i];
            sum -= (e - '0')*(pow(bas, count));
            count++;
        }
        return !sum;
    } else {
        int sum = 0;
        int count = 0;
        for (int i = a.size()-1; i >= 0; i--){
            char e = a[i];
            sum += (retVal(e))*(pow(bas, count));
            count++;
        }
        count = 0;
        for (int i = b.size()-1; i >= 0; i--){
            char e = b[i];
            sum += (retVal(e))*(pow(bas, count));
            count++;
        }
        count = 0;
        for (int i = s.size()-1; i >= 0; i--){
            char e = s[i];
            sum -= (retVal(e))*(pow(bas, count));
            count++;
        }
        return !sum;
    }


    
}


int main(){
    scoobydoobydoo();
    string a, b, s; cin >> a >> b >> s;


    for (int i = startingPoint(a, b, s); i <= 16; i++){
        if (isAdd(a, b, s, i)){
            cout << i << endl;
        }
    }



    return 0;
}
