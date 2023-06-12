#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index(char str, string tS){
  for (int j = 0; j < tS.size(); j++){
    if(tS[j] == str)
      return j;
  }

  return 0;
}

int main(){
  string tS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string input, output;
  int counter;

  cin >> input;

  for (int i = 0; i < input.size(); i += counter + 1){
    output += input[i];
    counter = index(input[i], tS);
  }

  cout << output << endl;

  return 0;

}
