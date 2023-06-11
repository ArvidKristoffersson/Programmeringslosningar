#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define all(x)  (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()

typedef long long ll;

ll linf = 1e15+1;

using namespace std;

inline void scoobydoobydoo(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

priority_queue<int> pq;

void insert(int element) {
    pq.push(element);
}

// Returnera det största elementet i heapen
int getMax(){
    return pq.top();
}

// Ta bort det största värdet i heapen
void removeMax(){
    pq.pop();
}

// Returnera antalet element i heapen
int getSize(){
    return pq.size();
}
