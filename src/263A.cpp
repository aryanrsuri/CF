#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int j = 0, k = 0;
  bool found = false;
  while (k <= 4 && !found) {
    j = 0;
    string line;
    getline(cin, line);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    for (char c : line) {
      if (c == '1') {
        found = true;
        break;
      }
      j++;
    }
    k++;
  }
  cout << abs(2 - j) + abs(3 - k);

  return 0;
}
