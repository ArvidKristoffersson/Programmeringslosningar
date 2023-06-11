#include <iostream>
#include <vector>

using namespace std; 

const int MAXN = 20;
int values[MAXN];
vector<int> calc[MAXN];
int finalValues[MAXN];

int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        cin >> values[i];
    }

    for (int i = 0; i < n+2; i++){
        vector<int> temp;
        temp.push_back(i);
        if (i != 0)temp.push_back(i-1);
        if (i > 1)temp.push_back(i-2);
        calc[i] = temp;
    }

    bool con = true;

    while (con){
        for (int i = n+1; i > -1; i--){
            int intusMaximus = -1, intus;
            for (int j = 0; j < calc[i].size(); j++){
                int e = calc[i][j];
                if (values[e] > intusMaximus){
                    intusMaximus = values[e];
                    intus = e;
                }

            }
            if (intusMaximus > 0){
                values[intus]--;
                finalValues[i]++;
            }
        }
        con = false;
        for (int i = 0; i < n; i++){
            if (values[i] > 0)con = true;
        }
    }

    int count = 0;


    for (int i = 0; i < n+2; i++){
        for (int j = 10; j > -1 && j > 10-finalValues[i]; j--){
            count += j;
        }
    }
    cout << count << endl;
    
    return 0;
}
