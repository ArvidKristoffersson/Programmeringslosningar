#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int input, a, b;
  vector<long long int> v;
  cin >> input;

  for (int i = 0; i < input; i++){
    cin >> a >> b; 
    v.push_back(pow(a, b));
  }

  for (int j = 0; j < v.size(); j++){
    cout << v[j] << endl; 
  }

  return 0;
}
