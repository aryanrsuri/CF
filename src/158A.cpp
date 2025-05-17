#include <ios>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  int adv = 0;
  std::cin >> n >> k;
  std::cin.ignore();
  vector<int> s(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (auto x : s) {
    if (x > 0 && x >= s[k - 1]) {
      adv++;
    }
  }

  cout << adv;
  return 0;
}
