#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

const int lul = 1e4;
int board[lul][lul];

int main(){
    //Input
    int q; int numbers; 
    cin >> q >> numbers; 
    vector<vector<int> > v; 
    vector<int> tV, tV2;

    //!Generera alla subsets!
    
    //Alla rader

    for (int i = 0; i < q; i++){
        for (int j = 0; j < q; j++){
            cin >> board[i][j];
            tV.push_back(board[i][j]);
        }
        v.push_back(tV);
        tV.clear();
    }

    //Alla kolumner

    for (int i = 0; i < q; i++){
        for (int j = 0; j < q; j++){
            tV.push_back(board[j][i]);
        }
        v.push_back(tV);
        tV.clear();
    }

    //Alla diagonaler (2)

    for (int i = 0, j = q-1; i < q; i++){
        tV.push_back(board[i][i]);
        tV2.push_back(board[j][i]);
        j--;
    }
    v.push_back(tV);
    v.push_back(tV2);

    //Gå igenom siffrorna, ta bort tal som finns i subsets, i när subset = 0 är svar

    for (int i = 0; i < numbers; i++){
        int num; cin >> num; 
        for (int j = 0; j < v.size(); j++){
            if (count(all(v[j]), num)){
                int it = find(all(v[j]), num) - v[j].begin();
                v[j].erase(v[j].begin() + it);
                if (v[j].size() == 0){
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;





    return 0;
}
