#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 

pair<char, int> arr[2][5];

int main(){
    char c; int t; bool Player = true, a = false, b = false;
    vector<char> alreadyPlayed[2];
    for (int i = 0; i < 5; i++){
        cin >> c >> t;
        arr[0][i] = {c, t};
    }
    for (int i = 0; i < 5; i++){
        cin >> c >> t;
        arr[1][i] = {c, t};
    }

    //Game

    for (int i = 0; i < 5; i++){
        //Vinnare av stick
        if (Player){
            if (arr[0][i].first == arr[1][i].first){
                if (arr[0][i].second < arr[1][i].second){
                    Player = false;
                }
            } else {
                alreadyPlayed[1].push_back(arr[0][i].first);
            }
        } else {
            if (arr[0][i].first == arr[1][i].first){
                if (arr[1][i].second < arr[0][i].second)Player = true;
            } else {
                alreadyPlayed[0].push_back(arr[1][i].first);
            }
        }


        if (count(all(alreadyPlayed[0]), arr[0][i].first))a = true;
        if (count(all(alreadyPlayed[1]), arr[1][i].first))b = true;
        //Fuskar
    }


    if (Player){
        cout << 'A' << endl;
    } else {
        cout << 'B' << endl;
    }

    if (a && b){
        cout << "A och B fuskar" << endl;
    } else if (a){
        cout << "A fuskar" << endl;
    } else if (b){
        cout << "B fuskar" << endl;
    }




    return 0;
}
