#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  // @@ - getline(cin, s) @@ since cin >> s reads faster and is more idiomatic
  cin >> s;
  char p = s[0];
  int count = 0;
  for (char c : s) {
    if (c == p) {
      count++;
    } else {
      count = 1;
    }
    if (count >= 7) {
      cout << "YES";
      return 0;
    }
    p = c;
  }
  cout << "NO";
  return 0;
}
