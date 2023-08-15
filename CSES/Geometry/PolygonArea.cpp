#include <iostream>
#include <vector>
 
using namespace std; 
 
struct P
{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    P operator- (const P& b) const{
        return P{x - b.x, y - b.y };
    }
    void operator-= (const P& b){
        x -= b.x;
        y -= b.y;
        return;
    }
    long long operator* (const P& b) const{
        return (long long) x * b.y - (long long) y * b.x;
    }
    long long triangle(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }
};
 
 
void run(int n){
    vector<P> v;
    for (int i = 0; i < n; i++){
        P t;
        t.read();
        v.push_back(t);
    }
 
    long long ans = 0;
 
    for (int i = 0; i < n; i++){
        ans += v[i] * v[i+1 == n ? 0 : i+1];
    }
 
 
    cout << abs(ans) << endl;
 
    return;
}
 
 
int main(){
    int n; cin >> n;
    run(n);
 
 
 
    return 0;
}
