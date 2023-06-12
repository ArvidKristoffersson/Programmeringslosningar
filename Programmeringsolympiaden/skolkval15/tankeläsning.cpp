#include <iostream>
#include <vector>

using namespace std; 

int main(){
    vector<double> v, l; 
    double n; cin >> n;
    char c, q;

    for (double i = 0; i < 30; i++)v.push_back(i);
    for (double i = 0; i < 30; i++)l.push_back(i*(-1));

    for (double i = 0; i < n; i++){
        cin >> c >> q;

        if (c == '-'){
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j;
                else p = q - '0';
                v[j] -= p;
            }
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j*(-1);
                else p = q - '0';
                l[j] -= p;
            }
        }
        if (c == '+'){
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j;
                else p = q - '0';
                v[j] += p;
            }
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j*(-1);
                else p = q - '0';
                l[j] += p;
            }
        }
        if (c == '*'){
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j;
                else p = q - '0';
                v[j] *= p;
            }
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j*(-1);
                else p = q - '0';
                l[j] *= p;
            }
        }
        if (c == '/'){
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j;
                else p = q - '0';
                v[j] /= p;
            }
            for (double j = 0; j < 30; j++){
                double p;
                if (q == 'x')p = j*(-1);
                else p = q - '0';
                l[j] /= p;
            }
        }
    }

    double phew = v[0];
    bool cool = true;
    if (phew != (int)phew)cool = false;
    for (double e : v){
        if (e != phew)cool = false;
    }

    if (cool)cout << phew << endl;
    else cout << "Nej" << endl;


    return 0;
}
