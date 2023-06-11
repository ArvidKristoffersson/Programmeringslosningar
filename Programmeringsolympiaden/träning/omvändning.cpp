#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
   string tempWord;
   vector<string> allWords;
   int wordCount;

   cin >> wordCount;

   for (int i = 0; i < wordCount; i++){
    cin >> tempWord;
    allWords.push_back(tempWord);
   }

   reverse(allWords.begin(), allWords.end());

   for (int j = 0; j < allWords.size(); j++){
    tempWord = allWords[j];
    cout << tempWord << endl;
   }

    return 0;
}
