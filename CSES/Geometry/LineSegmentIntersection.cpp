#include <iostream>
 
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
 
 
void run(){
    P p1, p2, p3, p4;
    p1.read(); p2.read(); p3.read(); p4.read();
 
    if ((p2 - p1) * (p4 - p3) == 0){
        if (p1.triangle(p2, p3) != 0){
            cout << "NO" << endl;
            return;
        }
        for (int i = 0; i < 2; i++){
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                cout << "NO" << endl;
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES" << endl;
        return;
    }
 
    for (int i = 0; i < 2; i++){
        long long side1 = p1.triangle(p2, p3);
        long long side2 = p1.triangle(p2, p4);
        if ((side1 < 0 && side2 < 0) || (side1 > 0 && side2 > 0)){
            cout << "NO" << endl;
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
 
    cout << "YES" << endl;
    return;
}
 
 
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        run();
    }
    return 0;
}
