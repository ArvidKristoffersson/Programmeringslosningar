#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

#define all(x) (x).begin(), (x).end()

using namespace std;

void printV(vector<long long> v, string id){
    cout << id << ": ";
    for (auto e : v){
        cout << e << " ";
    }
    cout << endl;
    return;
}

int main() {
    map<long long, bool> m;
    vector<long long> dup, leftover;
    vector<long long> ans, stac;
    long long n, q, k;
    cin >> n >> q >> k;

    for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    if (m[t]) {
        dup.push_back(t);
    } else {
        --k;
    }
        m[t] = true;
    }

    vector<long long> temp;

    for (long long i = 0; i < q; i++) {
        long long t;
        cin >> t;
        temp.push_back(t);
    }

    for (long long i = 0; i < dup.size(); i++) {
        dup[i] = temp[dup[i] - 1];
    }

    for (long long i = 0; i < temp.size(); i++) {
        if (!m[i + 1]) {
            leftover.push_back(temp[i]);
        }
    }


    if (k <= 0) {
        cout << 0 << endl;
        return 0;
    }



    long long j = 0, i = 0;
    sort(all(dup));
    sort(all(leftover));

    for (int j = 0; j < leftover.size(); j++) {
        if (i < dup.size()){
            while (leftover[j] > dup[i]){
                stac.push_back(dup[i]);
                i++;
                if (i >= dup.size())break;
            }
        }

        if (!stac.empty()){
            ans.push_back(leftover[j] - stac[stac.size()-1]);
            stac.pop_back();
        }

    }
    sort(all(ans));


    if (ans.size() == 0) {
    cout << -1 << endl;
    return 0;
    }

    long long int prefix = 0;

    for (long long i = 0; i < k; i++) {
        if (i >= ans.size()){
            cout << -1 << endl;
            return 0;
        }
        prefix += ans[i];
    }

    cout << prefix << endl;

    return 0;
}
