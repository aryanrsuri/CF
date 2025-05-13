#include <cctype>
#include <cstdlib>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int value, r = 0, c = 0;
  for (size_t i = 0; i <= 4; ++i) {
    for (size_t j = 0; j <= 4; ++j) {
      cin >> value;
      if (value == 1) {
        r = i;
        c = j;
      }
    }
  }

  cout << abs(2 - r) + abs(2 - c) << '\n';

  return 0;
}
