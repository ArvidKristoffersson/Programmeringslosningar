#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int letters, words, counter;
  string tS, tLine = "";

  vector<string> lines, wordV;

  cin >> letters >> words;

  for (int i = 0; i < words; i++){
    cin >> tS;
    if (tLine.size() >= letters){
      lines.push_back(tLine);
      tLine = "";
    }
    tLine += tS + " ";
  }

  lines.push_back(tLine);

  for (int j = 0; j < lines.size(); j++){
    cout << lines[j] << endl;
  }

  

  return 0;
}
