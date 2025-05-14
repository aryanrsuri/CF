#include <cmath>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, n, w;
  cin >> k >> n >> w;

  for (size_t i = 1; i < w + 1; ++i) {
    n -= i * k;
  }

  if (n > 0) {
    cout << 0;
  } else {
    cout << abs(n);
  }

  return 0;
}
