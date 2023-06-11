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

vector<int> start;
vector<int> want;
map<vector<int>, bool> M;

void printV(vector<int> printingV){
    for (auto e : printingV){
        cout << e << " ";
    }
    cout << endl;
}

vector<int> makeMove(const vector<int> nV, int a, int dir){
    vector<int> v = nV;
    int k = v[a];
    v[a] = 0;
    if (dir == 1){
        int i = 0;
        while (k--){
            if (a+i == 5){
                a -= 5;
            }
            v[a+i]++;
            i++;
        }
    } else {
        int i = 0;
        while (k--){
            if (a+i < 0){
                a += 5;
            }
            v[a+i]++;
            i--;
        }
    }
    return v;
}

int main(){
    for (int j = 0; j < 5; j++){
        int t; cin >> t;
        start.push_back(t);
    }
    for (int j = 0; j < 5; j++){
        int t; cin >> t;
        want.push_back(t);
    }

    vector<int> test = makeMove(want, 0, -1);

    queue<pair<vector<int>, int> > q;
    q.push({start, 0});

    while (!q.empty()){
        vector<int> l = q.front().first;
        int w = q.front().second;
        q.pop();
        if (l == want){
            cout << w << endl;
            return 0;
        }

        if (M.find(l) == M.end()){
            M[l] = true;
            for (int i = 0; i < l.size(); i++){
                if (l[i] > 1){
                    q.push({makeMove(l, i, 1), w+1});
                    q.push({makeMove(l, i, -1), w+1});
                }
            }
        }
    }
    cout << "nej" << endl;

    return 0;
}
