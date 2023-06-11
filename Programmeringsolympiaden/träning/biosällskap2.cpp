#include <iostream>

using namespace std; 

int main(){
    int x, n; cin >> x >> n;
    int arr[n], sum = 0, ans = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (sum + arr[i] <= x){
            sum += arr[i];
        } else {
            x = 0;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
