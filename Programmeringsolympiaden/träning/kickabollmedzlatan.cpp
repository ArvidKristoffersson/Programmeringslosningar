#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int tInt, seasons, first;

  vector<string> v;

  cin >> seasons >> first;

  for (int i = 0; i < seasons-1; i++){
    cin >> tInt;
    if (tInt > first){
      v.push_back("Better");
    } else if (tInt < first){
      v.push_back("Worse");
    } else {
      v.push_back("Equal");
    }
    
  }

  for (int j = 0; j < v.size(); j++){
    cout << v[j] << endl;
  }


  return 0;
}
