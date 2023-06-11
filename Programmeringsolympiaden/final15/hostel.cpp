#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<int> > bubbleSort(vector<int> c, vector<int> number){
    for (int i = 0; i < c.size() - 1; i++){
        for (int j = 0; j < c.size() - i - 1; j++){
            if (c[j] > c[j+1]){
                swap(c[j], c[j+1]);
                swap(number[j], number[j+1]);
            }
        }
    }
    vector<vector<int> > v; 
    v.push_back(c);
    v.push_back(number);

    return v;
}

int main(){
    int n, m, tot = 0; cin >> n >> m;
    vector<int> cost, num;

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        cost.push_back(a);
        num.push_back(b);
    }

    vector<vector<int> > q = bubbleSort(cost, num);

    cost = q[0];
    num = q[1];

    //cout << cost[0] << " " << num[0] << endl;

    for (int i = 0; i < cost.size(); i++){
        while (num[i] > 0 && n > 0){
            num[i]--;
            n--;
            tot += cost[i];
        }
    }

    cout << tot << endl;
    

    return 0; 
}
