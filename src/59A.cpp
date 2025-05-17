#include <cctype>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string w;
  int i = 0;
  cin >> w;

  for (char &c : w) {
    if (c > 96) {
      --i;
    } else {
      ++i;
    }
  }

  if (i > 0) {
    for (char &c : w) {
      c = std::toupper(c);
    }
  } else {
    for (char &c : w) {
      c = std::tolower(c);
    }
  }

  cout << w;

  return 0;
}
