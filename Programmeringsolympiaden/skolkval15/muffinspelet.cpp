#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int a = 0, b = 0, it = 0, max;
  double muffins;

  cin >> muffins;

  while (muffins > 0){
    if ((int)muffins%2 == 0){
      max = muffins/2; 
    } else {
      max = ceil(muffins/2); 
    }

    if (it%2 == 0){
      a += max;
    } else {
      b += max; 
    }

    muffins -= max; 

    it++;
  }


  cout << b << " " << a << endl; 



  return 0;
}
