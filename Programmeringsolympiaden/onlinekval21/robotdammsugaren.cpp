#include <iostream>
#include <string>

using namespace std; 

const int MAXN = 1e4;
char board[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
char n_colour = '#';
int ans = 0;
string kom; 


void recursion(int r, int c, char dir, int i){
  if (i >= kom.size())return;
  if (board[r][c] == n_colour){
    char kekw = dir;
    dir = kom[i+1];
    i++;
    if (kekw == '<'){
      recursion(r, c+1, dir, i);
    } else if (kekw == '>'){
      recursion(r, c-1, dir, i);
    } else if (kekw == '^'){
      recursion(r+1, c, dir, i);
    } else {
      recursion(r-1, c, dir, i);
    }
    return;
  }

  if (!isVisited[r][c])ans++;
  isVisited[r][c] = true;

  if (dir == '<'){
    recursion(r, c-1, dir, i);
  } else if (dir == '>'){
    recursion(r, c+1, dir, i);
  } else if (dir == '^'){
    recursion(r-1, c, dir, i);
  } else {
    recursion(r+1, c, dir, i);
  }


  return;
}



int main(){
  int r, c, n, rootX, rootY; cin >> r >> c >> n;
  cin >> kom;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> board[i][j];
      if (board[i][j] == 'O'){
        rootX = i;
        rootY = j;
      }
    }
  }

  recursion(rootX, rootY, kom[0], 0);

  cout << ans << endl;

  
  


  return 0;
}
