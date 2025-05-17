#include <ios>
#include <iostream>
#include <set>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;

  if (t % 4 == 0 || t % 7 == 0 || t % 47 == 0 || t % 74 == 0 || t % 477 == 0 ||
      t % 774 == 0) {
    cout << "YES" << "\n";
    return 0;
  }
  std::set<int> v;
  while (t > 0) {
    v.insert(t % 10);
    t /= 10;
  }

  for (int x : v) {
    if (x != 4 && x != 7) {
      cout << "NO" << "\n";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}
