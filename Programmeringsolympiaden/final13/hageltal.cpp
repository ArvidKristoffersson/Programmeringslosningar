#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)  (x).begin(), (x).end()

using namespace std; 
vector<int> v;
const long long int uaeg = 1e9;

bool isVisited[uaeg];

vector<int> hailStone(int x){
    if (isVisited[x] || x == 1){
        if (x != 4)v.push_back(x);
        return v;
    }
    isVisited[x] = true;
    v.push_back(x);
    if  (x%2 == 0){
        return hailStone(x/2);
    }
    return hailStone(x*3+1);
}

int main(){
    //Input
    int a, b; cin >> a >> b;

    vector<int> first = hailStone(a);
    v.clear();
    vector<int> sec = hailStone(b);

 
    int it = find(all(first), sec[sec.size()-1]) - first.begin() - 1;
    cout << sec.size() + it << endl;
    return 0;





    return 0;
}
