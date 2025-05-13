#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::string s;
  std::vector<char> n;
  getline(cin, s);
  for (char ch : s) {
    if (isdigit(ch)) {
      n.push_back(ch);
    }
  }
  std::sort(n.begin(), n.end());
  for (size_t i = 0; i < n.size(); ++i) {
    cout << n[i];
    if (i < n.size() - 1) {
      cout << "+";
    }
  }

  return 0;
}
