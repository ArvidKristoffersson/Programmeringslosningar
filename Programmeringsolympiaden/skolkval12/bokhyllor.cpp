#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, s; cin >> a >> b >> c >> s;
    int shelf, nS = 0;

    while (a || b || c){
        shelf = s;
        if (c){
            for (int i = 0; i < c + 1; i++){
                if (shelf - 3*(i+1) < 0 || i == c){
                    shelf -= 3*i;
                    c -= i;
                    break;
                }
            }
        }

        if (b){
            for (int i = 0; i < b + 1; i++){
                if (shelf - 2*(i+1) < 0 || i == b){
                    shelf -= 2*i;
                    b -= i;
                    break;
                }
            }
        }

        if (a){
            for (int i = 0; i < a + 1; i++){
                if (shelf - (i+1) < 0 || i == a){
                    shelf -= i;
                    a -= i;
                    break;
                }
            }
        }
        nS++;
    }


    cout << nS << endl;


    return 0;
}
