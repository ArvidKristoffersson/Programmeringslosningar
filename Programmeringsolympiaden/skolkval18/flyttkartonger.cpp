#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> v;

ll maximus = 1e9 + 1;

bool calc(ll it) {
  vector<ll> q = v;
  q[0] += it;
  for (int i = 0; i < q.size() - 1; i++) {
    if (q[i + 1] > q[i])
      return false;
    double t = q[i] - q[i + 1];
    q[i] -= floor(t / 2);
    q[i + 1] += floor(t / 2);
  }

  return true;
}

void binarySearch() {
  ll a = 0, b = maximus, minimus;
  while (a <= b) {
    double q = a + b;
    ll k = floor(q / 2);
    if (calc(k)) {
      minimus = k;
      b = k - 1;
    } else {
      a = k + 1;
    }
  }

  cout << minimus << endl;
  return;
}

int main() {
  int n, t, highPoint = 0;
  cin >> n;
  bool fin = false;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
    highPoint = max(highPoint, t);
  }
  binarySearch();

  return 0;
}
