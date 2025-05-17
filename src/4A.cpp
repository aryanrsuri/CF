#include <ios>
#include <iostream>
int w;
void solve() {
  if (w != 2 && w % 2 == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> w;
  solve();

  return 0;
}
