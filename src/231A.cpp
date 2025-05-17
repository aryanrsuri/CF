#include <ios>
#include <iostream>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  int win = 0;
  std::cin >> t;
  while (t--) {
    int a, b, c, sum;
    std::cin >> a >> b >> c;
    sum = a + b + c;
    if (sum > 1) {
      win++;
    }
  }
  std::cout << win;

  return 0;
}
