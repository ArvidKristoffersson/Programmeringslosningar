#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b, c, count = 0, N;
  cin >> N;
  for(a = 1; a <= N; a++) {
    for(b = a; b <= N; b++) {
      c = floor(sqrt(a*a+b*b-a*b));
      if(c<=N && c*c==a*a+b*b-a*b) 
        count++;
    }
  }
  cout << count << endl; 
  return 0;
}
