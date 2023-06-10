#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<vector<int> > > generatePosition(int strS, int iX, int iY){
    vector<vector<int> > v;
    int arr[iX][iY];
    vector<int> pair;
    for (int i = 0; i < iX; i++){
        for (int j = 0; j < iY; j++){
            arr[i][j] = 0; 
        }
    }

    int x = 0, y = 0, i = 0, dX = -1, dY = -1;
    while (i < strS){
        if(arr[x][y] != 1){
            arr[x][y] = 1;
            pair.push_back(x); 
            pair.push_back(y);
            v.push_back(pair);
            i++;
            pair.clear();
        }
        if (x == 0 || x == iX-1) dX *= -1;
        if (y == 0 || y == iY-1) dY *= -1;
        x += dX; 
        y += dY; 
    }
    vector<vector<vector<int> > > g; 
    g.push_back(v);
    sort(v.begin(), v.end());
    g.push_back(v);


    return g; 
}

void readThrough(vector<vector<vector<int> > > v, string str, int iX, int iY){
    char arr[iX][iY];
    for (int i = 0; i < v[1].size(); i++){
        arr[v[1][i][0]][v[1][i][1]] = str[i]; 
    }
    int x = 0, y = 0, i = 0, dX = -1, dY = -1;
    string newString = ""; 
    for(int i = 0; i < v[0].size(); i++){
        newString += arr[v[0][i][0]][v[0][i][1]];
    }

    cout << newString << endl; 



}

int main(){
    int a, b; 
    string line; 
    cin >> a >> b >> line;
    vector<vector<vector<int> > > pairs; 
    pairs = generatePosition(line.size(), a, b);
    readThrough(pairs, line, a, b);


    return 0; 
}
