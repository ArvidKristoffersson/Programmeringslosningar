#include <iostream>
 
using namespace std; 
 
int main(){
    double x1, y1, x2, y2, x3, y3, n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x2 -= x1; x3 -= x1;
        y2 -= y1; y3 -= y1;
        double k = x2 * y3 - x3*y2;
        if (k > 0){
            cout << "LEFT" << endl;
        } else if (k < 0){
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
 
    }
 
    return 0;
}
