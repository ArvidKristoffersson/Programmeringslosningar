#include <iostream>
#include <map>
#include <cmath>

using namespace std; 

const int MAXN = 1e6;
int arr[MAXN];

int answer = 0;

void binarySearch(int x, int i, int ans){
    int a = 0, b = i-1;
    while (a <= b){
        double q = a + b;
        int k = floor(q/2);
        if (x - arr[k] == ans){
            answer++;
            return;
        }
        if (x - arr[k] < ans)b = k-1;
        else a = k+1;
    }
}

int main(){
    map<int, int> m;
    m[0] = 6; m[1] = 2; m[2] = 5; m[3] = 5; m[4] = 4; m[5] = 5; m[6] = 6; m[7] = 3; m[8] = 7; m[9] = 6;

    int h, ms, s;
    arr[0] = 0;

    int c; cin >> c;

    for (int i = 0; i < 24; i++){
        h = m[i%10] + m[(i-i%10)/10];
        for (int j = 0; j < 60; j++){
            ms = m[j%10] + m[(j-j%10)/10];
            for (int k = 0; k < 60; k++){
                s = m[k%10] + m[(k-k%10)/10];
                arr[i*3600+j*60+k+1] = arr[i*3600+j*60+k] + h + ms + s;
                binarySearch(arr[i*3600+j*60+k+1], i*3600+j*60+k+1, c);
            }
        }
    }

    cout << answer << endl;
    return 0;
}
