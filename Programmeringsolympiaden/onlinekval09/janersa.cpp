#include <iostream>

using namespace std; 

const int MAXN = 101;
const int MAXM = 501;
int adj[MAXN][MAXN], dist[MAXN][MAXN];

int main(){
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = MAXM;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        }
    }

    int x, y;

    int distances = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] > distances){
                distances = dist[i][j];
                x = i, y = j;
            }
        
    }

    if (x > y){
        int q = y;
        y = x;
        x = q;
    }

    cout << x << " " << y << " " << distances * 100 << endl;




    return 0;
}
