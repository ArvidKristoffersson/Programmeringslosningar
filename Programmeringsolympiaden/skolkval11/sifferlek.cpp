#include <iostream>
#include <string>

using namespace std; 


int multSum(int a){
  int digitProduct; 
  int reminder; 
  for (digitProduct = 1; a > 0; a = a / 10)
  {
    reminder = a % 10;
    digitProduct = digitProduct * reminder;
  }
  
  if(digitProduct >= 10){
    return multSum(digitProduct);
  } else {
    return digitProduct;
  }
 
  
};

int getSum(int a)
{
  int sum = 0;
  while (a != 0) {
    sum = sum + a % 10;
    a = a / 10;
  }

  if(sum > 10){
    return getSum(sum);
  } else {
    return sum;
  }
}

int main(){
  int a, b, totSum = 0;
  cin >> a >> b; 

  
  for (int i = a; i < b + 1; i++){
    if (getSum(i) == multSum(i)){
      totSum++;
    } 

  }

  cout << totSum << endl; 

  return 0; 
}
