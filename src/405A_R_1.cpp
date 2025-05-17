/**
 * author: Aryan Suri
 * date: 2025-05-17T14:39:22-700
 * licence: MIT
 **/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  vector<int> c;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    c.push_back(x);
  }

  std::sort(c.begin(), c.end());
  for (int n : c) {
    cout << n << " ";
  }

  return 0;
}
