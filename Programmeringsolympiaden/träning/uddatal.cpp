#include <iostream>
#pragma GCC optimize("Ofast,inline") 
#pragma GCC optimize ("unroll-loops")

using namespace std; 

inline void scoobydoobydoo()
{
  std::ios_base::sync_with_stdio(false);
  std::ios_base::sync_with_stdio(false);
  static_cast<std::basic_ios<char>&>(std::cin).tie(NULL);
  static_cast<std::basic_ios<char>&>(std::cout).tie(NULL);
}


int main()
{
  scoobydoobydoo();
  long long n;
  std::cin.operator>>(n);
  bool cool = true;
  for(int i = 1; i < n; i++) {
    cool = !cool;
  }
  
  if(cool) {
    std::operator<<(std::cout, "ja").operator<<(std::endl);
    _Exit(0);
  } 
  
  std::operator<<(std::cout, "nej").operator<<(std::endl);
  _Exit(0);
}
