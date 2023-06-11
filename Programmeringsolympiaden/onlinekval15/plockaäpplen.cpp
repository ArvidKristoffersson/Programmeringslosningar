#include <iostream>

using namespace std; 

const int MAXN = 1e5;
int sum[2][MAXN], k, n;
int ans = -1;
bool isVisited[2][MAXN];

void dfs(int r, int c, int it, int w){
    ans = max(ans, w);

    if (r < 0 || r > 1 || c < 0 || c > n || sum[r][c] == -1 || isVisited[r][c] || it == k)return;
    //cout << w << endl;

    isVisited[r][c] = true;
    dfs(r-1, c, it+1, w+sum[r][c]);
    dfs(r+1, c, it+1, w+sum[r][c]);
    dfs(r, c-1, it+1, w+sum[r][c]);
    dfs(r, c+1, it+1, w+sum[r][c]);
    isVisited[r][c] = false;

    return;
}

int main(){
    cin >> n >> k;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < MAXN; j++){
            sum[i][j] = -1;
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> sum[i][j];
        }
    }

    dfs(1, 0, 0, 0);

    cout << ans << endl;


    return 0;
}
