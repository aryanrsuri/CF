#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned int n, c = 0;
  float s = 0;
  cin >> n;
  vector<int> v(n);
  for (size_t j = 0; j < n; ++j) {
    cin >> v[j];
    s += float(v[j]);
  }
  s = s / 2;
  std::sort(v.begin(), v.end(), std::greater<>());
  for (size_t i = 0; i < n; ++i) {
    c += v[i];
    if (c > s) {
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}
