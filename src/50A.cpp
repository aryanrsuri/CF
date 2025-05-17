#include <cmath>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int m, n, c;
  std::cin >> m >> n;
  c = m * n;

  // I could forgo the conditional and just return floor(c/2) since
  // floor(even/2) == even/2
  if (c % 2 == 0) {
    cout << c / 2;
  } else {
    cout << floor(c / 2);
  }

  return 0;
}
