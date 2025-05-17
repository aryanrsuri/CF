#include <ios>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, cnt = 0;
  std::vector<char> s;
  cin >> t;
  char c;
  while (t--) {
    cin >> c;
    s.push_back(c);
    if (c == s[s.size() - 2]) {
      ++cnt;
    }
  }

  cout << cnt;

  return 0;
}
