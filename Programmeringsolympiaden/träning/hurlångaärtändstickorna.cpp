#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main(){
  vector<string> v;
  int N, W, D, L;

  cin >> N >> W >> D;

  for (int i = 0; i < N; i++){
    cin >> L; 
    if (L <= W && D != 0){
      v.push_back("Asken");
      D--;
    } else {
      v.push_back("Papperskorgen");
    }
  }

  for (int i = 0; i < v.size(); i++){
    cout << v[i] << endl; 
  }

  return 0;
}
