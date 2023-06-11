#include <iostream>
#include <string>
#include <map> 
#include <vector>

using namespace std; 

int main(){
    map<string, string> A, B;
    int q; cin >> q;
    vector<string> v;
    string t1, t2;

    for (int i = 0; i < q; i++){
        cin >> t1 >> t2;
        if (!B[t2].empty() && A[t1].empty()){
            A[t1] = B[t2];
        } 
        else if (A[t1].empty() && B[t2].empty()){
            A[t1] = t1;
            B[t2] = t1;
        }
        else if (!A[t1].empty() && B[t2].empty()){
            B[t2] = A[t1];
        }
    }

    cin >> q;

    for (int i = 0 ; i < q; i++){
        cin >> t1;
        cout << A[t1] << " ";
    }

    cout << endl;





    return 0;
}
