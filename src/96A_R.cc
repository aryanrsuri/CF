#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  // More terse, but likely slower?
  if (s.find("0000000") != std::string::npos ||
      s.find("1111111") != std::string::npos) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
