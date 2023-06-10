#include <iostream>
#include <vector>

using namespace std; 

int main(){
    bool bjornFound = false;
    long long int n, t, sum = 0; cin >> n;
    vector<long long int> q; 
    long long int minimusIntus, minimusIndexius = 0;
    for (long long int i = 0; i < n - 1; i++){
        cin >> t;
        if (t == 0){
            i--;
            bjornFound = true;
            continue;
        } else {
            sum += t*(i+1);
            if (i != 0){
                t += q[i-1];
            }
            if (i == 0){
                minimusIntus = t;
            }
            if (t < minimusIntus){
                minimusIntus = t;
                minimusIndexius = i;
            }
            q.push_back(t);
        }
    }

    if (!bjornFound)cin >> t;

    if (minimusIntus > 0)minimusIntus = 0;

    sum += q[q.size()-1] - minimusIntus;

    cout << sum << endl;


    return 0;
}
