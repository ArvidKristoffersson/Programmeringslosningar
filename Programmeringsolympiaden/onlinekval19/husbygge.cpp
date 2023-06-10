//50 poäng
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

typedef long long ll;


const int MAXN = 10001;
ll board[MAXN][MAXN];
ll placed[MAXN][MAXN];

vector<pair<int, int> > testCase1(int n, int m, int k, bool dir){
    vector<pair<int, int> > v;
    for (int q = 0; q < k; q++){
        ll minimus = -1;
        int x, y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if ((q == 0 ? board[i][j] : placed[i][j] * board[i][j]) > minimus){
                    minimus = (q == 0 ? board[i][j] : placed[i][j] * board[i][j]);
                    x = i;
                    y = j;
                }
            }
        }
        if (dir){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    placed[i][j] = min(placed[i][j], (ll)(abs(x-i) + abs(y-j)));
                }
            } 
        } else {
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    placed[i][j] = min(placed[i][j], (ll)pow((abs(x-i) + abs(y-j)), 2));
                }
            }
        }
        v.push_back({x, y});

    }

    return v;
}

vector<pair<int, int> > test6(int n, int m, int k){
    vector<pair<int, int> > v;
    for (int s = 0; s < 500; s++){
        for (int h = 0; h < 200; h++){
            int minimus = -1;
            int x= -1, y= -1;
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 5; j++){
                    if (board[i][j] > minimus){
                        minimus = board[i][j];
                        x = s*2+i;
                        y = h*5+j;
                    }
                }
            }
            v.push_back({x, y});
        }
    }
    return v;
}






int main(){
    int t, n, m, k; cin >> t >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            placed[i][j] = (int) 1e9+1;
        }
    }
    vector<pair<int, int> > v;
    if (t == 7 || t == 8){
        v = testCase1(n, m, k, false);
    } else if (t != 4 && t != 6 && t != 9){
        v = testCase1(n, m, k, true);
    } else if (t == 6){
        v = test6(n, m, k);
    }


    for (auto e : v){
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }


    return 0;
}
