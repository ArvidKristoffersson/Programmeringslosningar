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

unordered_map<string, string> uM;

void uppdateraNummer(string namn, string nummer){
    uM[namn] = nummer;
}

bool raderaNummer(string namn){
    if (uM.find(namn) == uM.end())return false;

    uM.erase(namn);
    return true;
}

string uppslagning(string namn){
    if (uM.find(namn) == uM.end())return "finns ej";

    return uM[namn];
}
