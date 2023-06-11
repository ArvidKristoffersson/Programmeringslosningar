#include <iostream>
#include <vector>

using namespace std;

int main(){
  int amount, tempNum, nSum = 0;
  vector<int> v;

  cin >> amount;

  for (int i = 0; i < amount; i++){
    cin >> tempNum;
    v.push_back(tempNum);
  }

  for (int j = 0; j < v.size(); j++){
    nSum += v[j];
  }

  cout << nSum << endl;

  return 0;
}
