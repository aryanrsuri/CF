#include <ios>
#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string w;
    std::cin >> w;
    if (w.length() <= 10) {
      std::cout << w << "\n";
    } else {
      char f = w.front();
      char l = w.back();
      std::cout << f << w.length() - 2 << l << "\n";
    }
  }

  return 0;
}
