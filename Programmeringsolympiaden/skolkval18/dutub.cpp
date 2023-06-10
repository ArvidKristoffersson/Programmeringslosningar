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

map<char, int> M;
map<pair<int, int>, int> mem;
vector<pair<int, string>> videos;
int numberOfCategories;

int dp(int index, int categories){
    if (mem.find({index, categories}) != mem.end()){
        return mem[{index, categories}];
    }
    if (categories == (1 << numberOfCategories)-1){
        return 0;
    }
    if (index == videos.size())return 1e7;
  
    int best = 1e7;
    best = min(best, dp(index+1, categories));
    int nCat = categories;
    int cost = videos[index].first;
    int cat = 0;
    for (auto c : videos[index].second){
        cat += (1 << M[c]);
    }
    nCat |= cat;
    best = min(best, dp(index+1, nCat) + cost);

    return mem[{index, categories}] = best;
}

int main(){
    scoobydoobydoo();
    int count = 0;
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        int tid; cin >> tid;
        string s; cin >> s;
        videos.push_back({tid, s});
        for (auto e : s){
            if (M.find(e) == M.end()){
                M[e] = count;
                count++;
            }
        }
    }
    numberOfCategories = count;

    cout << dp(0, 0) << endl;




    return 0;
}
