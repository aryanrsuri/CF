#include <ios>
#include <iostream>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  int v = 0;
  std::cin >> t;
  while (t--) {
    std::string st;
    std::cin >> st;
    if (st.find("+") != std::string::npos)
      v++;
    else
      v--;
  }
  std::cout << v;

  return 0;
}
