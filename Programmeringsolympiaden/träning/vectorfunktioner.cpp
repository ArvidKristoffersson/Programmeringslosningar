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

// Vänd på en vektor.
// Notera att den skickas som referens, 
// så du ska vända samma vektor som skickas in.
void reverse(vector<int>& vec){
    reverse(all(vec));
}

// Välj ut vartannat element ur en vektor (första, tredje, osv)
// och returnera en ny vektor med svaret.
// Du får inte modifiera vektorn, trots att den skickas som referens.
// Därför används "const" framför parametern.
vector<int> vartannat(const vector<int>& vec){
    vector<int> ret;
    for (int i = 0; i < vec.size(); i+=2){
        ret.push_back(vec[i]);
    }
    return ret;
}

// Returnera det minsta värdet i en vektor.
int minsta(const vector<int>& vec){
    int minimus = 1e8;
    for (int i = 0; i < vec.size(); i++){
        minimus = min(minimus, vec[i]);
    }
    return minimus;
}

// Returnera summan av elementen i en vektor.
int summa(const vector<int>& sum){
    int r = 0;
    for (int i : sum){
        r += i;
    }
    return r;
}

// Räkna antalet udda heltal, som dessutom befinner
// sig på udda index (räknat noll-indexerat!)
int veryOdd(const vector<int>& suchVector){
    int ret = 0;
    for (int i = 1; i < suchVector.size(); i+=2){
        if (suchVector[i]%2 == 1){
            ret++;
        }
    }
    return ret;
}
