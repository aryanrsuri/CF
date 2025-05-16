#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, a = 0;
  string w;
  cin >> t;
  cin >> w;
  for (char c : w) {
    if (c == 'A') {
      ++a;
    } else {
      --a;
    }
  }

  if (a == 0) {
    cout << "Friendship" << "\n";
  } else if (a > 0) {
    cout << "Anton" << "\n";
  } else {
    cout << "Danik" << "\n";
  }

  return 0;
}
