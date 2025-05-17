/**
 * author: Aryan Suri
 * date: 2025-05-17T14:39:22-700
 * licence: MIT
 **/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, tt;
  vector<int> cols;
  cin >> t;
  tt = t;
  while (t--) {
    int n;
    cin >> n;
    cols.push_back(n);
  }
  while (tt--) {
    for (size_t i = 0; i < cols.size() - 1; ++i) {
      int d = cols[i] - cols[i + 1];
      if (d >= 0) {
        cols[i] -= d;
        cols[i + 1] += d;
      }
    }
  }

  for (auto e : cols) {
    cout << e << " ";
  }
  cout << "\n";

  return 0;
}
