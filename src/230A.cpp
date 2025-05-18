/**
 * author: Aryan Suri
 * licence: MIT
 **/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int s, n;
  cin >> s >> n;
  vector<std::pair<int, int>> D(n);
  for (auto &d : D) {
    cin >> d.first >> d.second;
  }
  sort(D.begin(), D.end());
  for (auto d : D) {
    if (s > d.first) {
      s += d.second;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}
