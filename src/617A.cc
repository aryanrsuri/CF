#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, s = 1;
  cin >> t;
  if (t < 6) {
    cout << 1;
    return 0;
  }
  while (t > 5) {
    t -= 5;
    ++s;
  }
  cout << s;

  return 0;
}
