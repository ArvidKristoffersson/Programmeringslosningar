#include <iostream>

using namespace std; 

int main(){
  int kg, tWeight = 0, it = 1, a = 1, b = 1, c;

  cin >> kg;

  kg *= 1000;

  while (tWeight <= kg){ 
    c = a + b;
    a = b; 
    tWeight += c;
    b = c; 
    it++;
  }


  cout << it << endl; 


  return 0;
}
