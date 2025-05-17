#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::string s;
  cin >> s;

  if (s[0] > 96 && s[0] < 123) {
    s[0] -= 32;
  }
  cout << s;

  return 0;
}
