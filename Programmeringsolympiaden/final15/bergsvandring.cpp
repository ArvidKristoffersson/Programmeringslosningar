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

const int MAXN = 1e3+1;
double mem[MAXN];
pair<double, double> points[MAXN];
vector<int>  adj[MAXN];
double d;

double dp(int index){
    if (index == 0)return 0;
    if (mem[index] != -1)return mem[index];
  
    double x = points[index].first;
    double y = points[index].second;   
    double ret = 1e9;
    pair<double, double> maxi = {0, 0};
    double neighX = points[index-1].first;
    double neighY = points[index-1].second;

    if (abs(y-neighY)/abs(x-neighX) <= d){
        ret = min(ret, dp(index-1));
        maxi = {index-1, abs(y-neighY)/abs(x-neighX)};
    }

    for (auto& e : adj[index]){
        if (abs(points[e].second-y)/abs(x-points[e].first) <= d)ret = min(ret, dp(e)+sqrt(pow(abs(x-points[e].first), 2) + pow(abs(y-points[e].second), 2)));
    }

    return mem[index] = ret;
}

void buildAdj(int n){
    for (int i = 0; i < n; i++){
        double x = points[i].first;
        double y = points[i].second;
        double maxiS1 = (points[i+1].second-y)/(points[i+1].first-x);
        double maxiS2 = (-points[i-1].second + y)/(points[i-1].first - x);
        for (int j = i+2; j < n; j++){
            double neighY = points[j].second;
            double neighX = points[j].first;
            if (neighY < y)continue;
        
            double slop = abs(neighY-y)/abs(neighX-x);

            if (slop >= maxiS1){
                maxiS1 = slop;
                adj[j].push_back(i);
            }

        }
        for (int j = i-2; j >= 0; j--){
            double neighY = points[j].second;
            double neighX = points[j].first;
           
            double slop = (-neighY+y)/(neighX-x);
            if (neighY < y)continue;

            if (slop >= maxiS2){
                maxiS2 = slop;
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < MAXN; i++){
        mem[i] = -1;
    }
}

int main(){
    scoobydoobydoo();
    cout << fixed << setprecision(8);
    int n; cin >> n >> d;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }
    buildAdj(n);

    double ans = dp(n-1);
    if (ans > 2e8)cout << -1 << endl;
    else cout << ans << endl;


    return 0;
}
