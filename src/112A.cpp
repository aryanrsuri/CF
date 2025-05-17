#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::string a, b;
  cin >> a >> b;
  std::transform(a.begin(), a.end(), a.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  std::transform(b.begin(), b.end(), b.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  int c = a.compare(b);
  if (c > 0) {
    cout << 1;
  } else if (c == 0) {
    cout << 0;
  } else {
    cout << -1;
  }
  return 0;
}
