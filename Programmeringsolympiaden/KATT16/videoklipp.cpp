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

const int MAXN = 1e5+1;
int binPar[MAXN][31];

int X;

int jump(int node){
    int count = 0;
    int x = X;
    while (x){
        if (x&1){
            node = binPar[node][count];
        }
        count++;
        x = x >> 1;
    }
    return node;
}

void initIA(int K){
    for (int i = 1; i < 31; i++){
        for (int j = 0; j < K; j++){
            binPar[j][i] = binPar[binPar[j][i-1]][i-1];
        }
    }

   return;
}

void videos(int K, int M, int s[]){
    X = M-1;
    for (int i = 0; i < K; i++){
        binPar[i][0] = s[i];
    }
    initIA(K);

    return;
}


int clip(int I){
    return jump(I);
}
