#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std; 

const int MAXN = 101;
string arr[MAXN];
int n, m;
map<pair<pair<string, int>, vector<int> >, long long> M;

string shiftString(string s){
    string str = "";
    str += s[s.size()-1];
    for (int i = 0; i < s.size()-1; i++){
        str += s[i];
    }

    return str;
}

void printV(vector<int> rsy){
    for (auto e : rsy){
        cout << e << " ";
    }
    cout << endl;
    return;
}

long long recursion(string s, int k, vector<int> b){
    if (M.find({{s, k}, b}) != M.end()){
        return M[{{s, k}, b}];
    }
    if (b.size() == 1){
        return M[{{s, k}, b}] = 0;
    }
    if (k == n)return 1;
    string q = arr[k];
    for (int j = 0; j < m; j++){
        vector<int> v = {-1};
        for (int i = 1; i < b.size(); i++){
            if (q[b[i]] == '.'){
                v.push_back(b[i]);
            }
        }
        M[{{s, k}, b}] += recursion(q, k+1, v);
        q = shiftString(q);
    }

    return M[{{s, k}, b}];
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long sum = 0;
    string kekw = arr[0];
    
    for (int i = 0; i < m; i++){
        vector<int> v = {-1};
        for (int j = 0; j < m; j++){
            if (kekw[j] == '.'){
                v.push_back(j);
            }
        }
        sum += recursion(kekw, 1, v);
        kekw = shiftString(kekw);
        v.clear();
    }


    cout << sum << endl;


    return 0;
}
