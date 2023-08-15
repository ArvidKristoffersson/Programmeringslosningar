#include <iostream>
#include <vector>
 
using namespace std; 
 
struct P
{
    long long x, y;
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
 
 
bool intersect(P p1, P p2, P p3, P p4){
    if ((p2 - p1) * (p4 - p3) == 0){
        if (p1.triangle(p2, p3) != 0){
            return false;
        }
        for (int i = 0; i < 2; i++){
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
 
    for (int i = 0; i < 2; i++){
        long long side1 = p1.triangle(p2, p3);
        long long side2 = p1.triangle(p2, p4);
        if ((side1 < 0 && side2 < 0) || (side1 > 0 && side2 > 0)){
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
 
    return true;
}
 
 
bool onSegment(P A, P B, P C){
    if (A.triangle(B, C) != 0){
        return false;
    }
    return min(A.x, B.x) <= C.x && max(A.x, B.x) >= C.x && min(A.y, B.y) <= C.y && max(A.y, B.y) >= C.y;
}
 
 
 
void run(int n, int m){
    vector<P> v;
    for (int i = 0; i < n; i++){
        P t; t.read();
        v.push_back(t);
    }
 
 
    for (int i = 0; i < m; i++){
        P p;
        p.read();
        int count = 0;
        bool boundary = false;
        P out = P{p.x+1, 3* (long long) 1e9};
        for (int j = 0; j < n; j++){
            int k = (j == n-1 ? 0 : j+1);
            if (intersect(p, out, v[j], v[k])){
                count++;
            }
            if (onSegment(v[j], v[k], p)){
                boundary = true;
            }
        }
        if (boundary){
            cout << "BOUNDARY" << endl;
        } else if (count%2 == 0){
            cout << "OUTSIDE" << endl;
        } else {
            cout << "INSIDE" << endl;
        }
    }
 
    return;
}
 
 
 
int main(){
    int n, m; cin >> n >> m;
 
    run(n, m);
 
    return 0;
}
