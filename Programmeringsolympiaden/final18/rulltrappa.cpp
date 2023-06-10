#include <iostream>

using namespace std;

int main() {
  double m, s, g, a, b, l, r;
  cin >> m >> g >> s >> a >> b >> l >> r;
  double ahop = l / a + m / s;
  double lat = r / b + m / g;

  if (lat < ahop)
    cout << "latmask" << endl;
  else cout << "friskus" << endl;

  return 0;
}
