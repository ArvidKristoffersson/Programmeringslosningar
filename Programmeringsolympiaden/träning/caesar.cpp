#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f' ,'g' ,'h' , 'i' ,'j' ,'k' ,'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int k;
  string input, str = "";

  cin >> k >> input;

  for (int i = 0; i < input.size(); i++){
    auto it = find(v.begin(), v.end(), input[i]);
    int index = it - v.begin() + (26 - k);
    index %= 26;
    str += v[index]; 
  }

  cout << str << endl; 

  return 0;
}
