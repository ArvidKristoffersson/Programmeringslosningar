#include <iostream>
#include <queue>

using namespace std; 

const int MAXN = 1e5+1;
long long int ans[MAXN];

int main(){
    int n; cin >> n;
    priority_queue<pair<pair<long long int, long long int>, int > > pq;

    for (int i = 0; i < n; i++){
        long long int a, b; cin >> a >> b;
        a *= -1; b *= -1;
        pq.push({{a, b}, i});
    }

    long long int c = 0;

    while (!pq.empty()){
        long long int a = pq.top().first.first;
        long long int b = pq.top().first.second;
        int i = pq.top().second;

        pq.pop();
        if (c > a){
            c = a;
        }
        if (c <= b){
            ans[i] = 0;
        } 
        else {
            ans[i] = abs(b-c);
            c = b;
        }
    }


    for (int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }


    return 0;
}
