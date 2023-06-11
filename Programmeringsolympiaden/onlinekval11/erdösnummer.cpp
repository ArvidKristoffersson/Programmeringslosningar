#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 5 * 1e3 + 1;
const int HighestN = 1e7;
int distanceZ[MAXN];
vector<pair<int, int>> edges;

int main() {
  int n, klop;
  cin >> klop >> n;
  int cInt = 1;
  set<string> s;
  map<int, string> m;
  map<string, int> l;
  m[0] = "ERDOS";
  l["ERDOS"] = 0;
  s.insert("ERDOS");

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vector<string> q;
    for (int j = 0; j < a; j++) {
      string t;
      cin >> t;
      int sSize = s.size();
      s.insert(t);
      if (s.size() != sSize) {
        m[cInt] = t;
        l[t] = cInt;
        cInt++;
      }
      q.push_back(t);
    }
    for (int j = 0; j < q.size(); j++) {
      for (int k = 0; k < q.size(); k++) {
        if (k != j) {
          edges.push_back({l[q[j]], l[q[k]]});
        }
      }
    }
  }

  // BELLMAN

  for (int i = 0; i < 5000; i++) {
    distanceZ[i] = HighestN;
  }
  distanceZ[0] = 0;

  

  for (int i = 1; i < 5001; i++) {
    for (auto e : edges) {
      int q = e.first, p = e.second;
      distanceZ[q] = min(distanceZ[q], distanceZ[p] + 1);
      distanceZ[p] = min(distanceZ[p], distanceZ[q] + 1);
    }
  }

  vector<string> str;

  for (int i = 0; i < cInt; i++) {
    str.push_back(m[i]);
  }

  sort(str.begin(), str.end());

  for (int i = 0; i < str.size(); i++) {
    cout << str[i] << " " << distanceZ[l[str[i]]] << endl;
  }

  return 0;
}
