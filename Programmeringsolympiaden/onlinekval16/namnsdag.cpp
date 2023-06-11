#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
  vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'u', 'x', 'y', 'z'};
  vector<string> allNames, birthdays; 
  string temp, name;
  int input, totSum = 0; 

  cin >> name >> input; 

  for (int i = 0; i < name.size(); i++){
    temp = name;
    for (int j = 0; j < v.size(); j++){
      temp[i] = v[j]; 
      allNames.push_back(temp);
    }
  }

  for (int i = 0; i < input; i++){
    cin >> temp; 
    if (count(allNames.begin(), allNames.end(), temp) && totSum == 0){
      totSum = i + 1; 
    }  
  }

  cout << totSum << endl; 

  return 0; 
}
