#include <iostream>

using namespace std;

int main(){
  long long int input, pushups = 0, cPushups = 0;

  cin >> input;

  for (int i = 0; i < input; i++){
    pushups++;
    cPushups += pushups;
  }

  cout << cPushups << endl;

  return 0;
}
