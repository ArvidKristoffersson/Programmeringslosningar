#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, aTot = 0, bTot = 0, j = 0, i = 0; cin >> n;
    string str; cin >> str;


    while (aTot < 2 && bTot < 2){
        j++;
        int winningScore = 25;
        bool gameFinished = false;
        int a = 0, b = 0;
        while (!gameFinished){
            if (str[i] == 'A'){
                a++;
            } else {
                b++;
            }

            if (j == 3)winningScore = 15;

            if (a >= winningScore && a - 2 >= b){
                aTot++;
                gameFinished = true;
            } else if (b >= winningScore && b - 2 >= a){
                bTot++;
                gameFinished = true;
            }

            i++;

        }


    }

    cout << aTot << " " << bTot << endl;

    return 0;
}
