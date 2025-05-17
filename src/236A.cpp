#include <ios>
#include <iostream>
#include <set>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::string s;
  cin >> s;
  std::set<char> ch(s.begin(), s.end());
  if (ch.size() % 2 == 0) {
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }

  return 0;
}
