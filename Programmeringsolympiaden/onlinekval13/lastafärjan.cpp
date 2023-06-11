#include <iostream>

using namespace std;
 
int main(){
    int n, l, bil = 0, sum = -4, q;
    cin >> n >> l;
    bool done = false;

    for (int i = 0; i < n; i++){
        cin >> q;
        if (!done){
            sum += q+1;
            if (sum > l*4){
                done = true;
            } else {
                bil++;
            }
        }
    }
    
    cout << bil << endl;


    return 0;
}
