#include <cctype>
#include <ios>
#include <iostream>
using namespace std;
bool vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string w, r;
  cin >> w;
  for (char &c : w) {
    c = std::tolower(c);
    if (!vowel(c)) {
      r += '.';
      r += c;
    }
  }

  cout << r;

  return 0;
}
