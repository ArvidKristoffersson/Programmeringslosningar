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

struct Point {
    int x, y;
    bool operator<(const Point &other) {
		if (x == other.x) { return y < other.y; }
		return x < other.x;
	}
    void print(){
        cout << x << " " << y << endl;
        return;
    }
};

const int MAXN = 1e5+1;

int t, n;

double distance(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

pair<double, vector<Point>> ansFromTSP(vector<Point>& path){
    vector<Point> ret;
    double mini = 1e15;
    double cur = 0;
    for (int i = 1; i < n/2; i++){
        cur += distance(path[i], path[i-1]);
    }

    int j = n/2-1;
    int i = 0;

    int fP = -1, sP = -1;
    while (j < n){
        if (cur < mini){
            mini = cur;
            fP = i; sP = j;
        }
        i++;
        j++;
        cur -= distance(path[i], path[i-1]);
        cur += distance(path[j], path[j-1]);
    }

    for (int i = fP; i <= sP; i++){
        ret.push_back(path[i]);
    }

    return {mini, ret};
}

bool isVisited[MAXN];
vector<Point> retVec(vector<Point>& houses, int pos){

    vector<Point> ret = {houses[pos]};

    isVisited[pos] = true;

    double closestYet = 1e15;
    int closeNode = -1;
    for (int i = pos+1; i < houses.size() && i < pos+1000; i++){
        if (distance(houses[pos], houses[i]) < closestYet && !isVisited[i]){
            closestYet = distance(houses[pos], houses[i]);
            closeNode = i;
        }
    }
    for (int i = pos-1; i >= 0 && i > pos-1000; i--){
        if (distance(houses[pos], houses[i]) < closestYet && !isVisited[i]){
            closestYet = distance(houses[pos], houses[i]);
            closeNode = i;
        }
    }

    if (closeNode == -1)return ret;

    vector<Point> v = retVec(houses, closeNode);

    for (auto& e : v){
        ret.push_back(e);
    }
    
    return ret;
}


vector<Point> solve(vector<Point>& path){
    vector<Point> best = ansFromTSP(path).second;
    double weight = ansFromTSP(path).first;
    for (int i = 1; i < n; i += 64){
        swap(path[i], path[i-1]);
        if (ansFromTSP(path).first < weight+10000000){
            best = ansFromTSP(path).second;
            weight = ansFromTSP(path).first;
        } else {
            swap(path[i], path[i-1]);
        }
    }
    return best;
}

map<pair<int, int>, int> M;

int main(){
    scoobydoobydoo();
    cin >> t >> n;
    vector<Point> houses(n);
    for (int i = 0; i < n; i++){
        cin >> houses[i].x >> houses[i].y;
        M[{houses[i].x, houses[i].y}] = i+1;
    }

    sort(all(houses));

    vector<Point> v = retVec(houses, 0);

    for (int i = 0; i < houses.size(); i++){
        if (!isVisited[i]){
            v.push_back(houses[i]);
        }
    }

    vector<Point> ans;

    if (t < 9){
        ans = ansFromTSP(v).second;
    } else {
        ans = solve(v);
    }

    for (auto& e : ans){
        cout << M[{e.x, e.y}] << " ";
    }
    cout << endl;

    

    return 0;
}
