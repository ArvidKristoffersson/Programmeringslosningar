#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std;

int dices[3][4];
int input[20][3];

vector<int> remO(vector<int> v, int a){
    vector<int> temp = v;
    if(!count(all(v), a))return v;
    vector<int>::iterator it = find(all(temp), a);
    temp.erase(it);
    return temp;
}

void printV(vector<int> v){
    for (auto e : v){
        cout << e << " ";
    }
    cout << endl;
    return;
}

void printD(int dice){
    for (int i = 0; i < 4; i++){
        cout << dices[dice][i] << " ";
    }
    cout << endl;
    return;
}

pair<bool, int> inDices(int a){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (dices[i][j] == a){
                return {true, i};
            }
        }
    }
    return {false, -1};
}

int remainingSize(int dice){
    int count = 0;
    for (int i = 0; i < 4; i++){
        if (dices[i] == 0)count++;
    }
    return count;
}

void addToDices(int a, int dice){
    for(int i = 0; i < 4; i++){
        if (dices[dice][i] == 0){
            dices[dice][i] = a;
            return;
        }
    }
    return;
}

bool eval(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            //cout << dices[i][j] << " ";
            if (dices[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}


int main(){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 3; j++){
            cin >> input[i][j];
        }
    }

    dices[0][0] = input[0][0];
    dices[1][0] = input[0][1];
    dices[2][0] = input[0][2];

    vector<int> pos1, pos2, pos3;


    for(int i = 1; i < 13; i++){
        if (dices[0][0] != i){
            pos1.push_back(i);
        }
        if (dices[1][0] != i){
            pos2.push_back(i);
        }
        if (dices[2][0] != i){
            pos3.push_back(i);
        }
    }

    pos1 = remO(pos1, dices[1][0]);
    pos1 = remO(pos1, dices[2][0]);
    pos2 = remO(pos2, dices[0][0]);
    pos2 = remO(pos2, dices[2][0]);
    pos3 = remO(pos3, dices[1][0]);
    pos3 = remO(pos3, dices[0][0]);


    while(!eval()){
        for (int i = 1; i < 20; i++){
            bool h[3]; h[0] = false; h[1] = false; h[2] = false;
            for (int j = 0; j < 3; j++){
                pair<bool, int> p = inDices(input[i][j]);
                if(p.first){
                    //cout << p.second << endl;
                    h[p.second] = true;
                }
            }
            for (int j = 0; j < 3; j++){
                if (h[0]){
                    pos1 = remO(pos1, input[i][j]);
                }
                if (h[1]){
                    pos2 = remO(pos2, input[i][j]);
                }
                if (h[2]){
                    pos3 = remO(pos3, input[i][j]);
                }
            }
        }

        for (int i = 1; i < 13; i++){
            if (count(all(pos1), i) && !count(all(pos2), i) && !count(all(pos3), i)){
                addToDices(i, 0);
                pos1 = remO(pos1, i);
            } else if (!count(all(pos1), i) && count(all(pos2), i) && !count(all(pos3), i)){
                addToDices(i, 1);
                pos2 = remO(pos2, i);
            } else if (!count(all(pos1), i) && !count(all(pos2), i) && count(all(pos3), i)){
                addToDices(i, 2);
                pos3 = remO(pos3, i);
            }
        }

        if (pos1.size() == remainingSize(0)){
            for (int i = 0; i < pos1.size(); i++){
                addToDices(pos1[i], 0);
            }
            pos1.clear();
        }
        if (pos2.size() == remainingSize(1)){
            for (int i = 0; i < pos2.size(); i++){
                addToDices(pos2[i], 1);
            }
            pos2.clear();
        }
        if (pos3.size() == remainingSize(2)){
            for (int i = 0; i < pos3.size(); i++){
                addToDices(pos3[i], 2);
            }
            pos3.clear();
        }

    }


    vector<vector<int> > v;
    for (int i = 0; i < 3; i++){
        vector<int> t;
        for (int j = 0; j < 4; j++){
            t.push_back(dices[i][j]);
        }
        sort(all(t));
        v.push_back(t);
    }
    sort(all(v));

    for (vector<int> q : v){
        for (int e : q){
            cout << e << " ";
        }
        cout << endl;
    }

    





    return 0;
}
