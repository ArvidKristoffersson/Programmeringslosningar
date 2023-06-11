#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

vector<long long int> v, fib; 

vector<long long int> generateFibonacci(long long int max){
    fib.push_back(1);
    fib.push_back(1);
    long long int i = 1; 
    while(fib[i]+fib[i-1] <= max){
        fib.push_back(fib[i] + fib[i-1]);
        i++; 
    }
    return fib; 
}

void everything(long long int max){
    fib = generateFibonacci(max);
    vector<long long int> v;

    for (int i = fib.size()-1; i > -1; i--){
        if(max <= 0){
            cout << v.size() << endl;
            for (int j = 0; j < v.size(); j++){
                cout << v[j] << endl;
            }
            return; 
        }
        for(int j = 0; j < floor(max / fib[i]); j++){
            v.push_back(fib[i]);
        }
        max %= fib[i];
    }
}

int main(){
    long long int ans;
    cin >> ans; 
    everything(ans);
    return 0; 
}
