/**
 * author: Aryan Suri
 * date: 2025-05-17T14:39:22-700
 * licence: MIT
 **/
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  int x = a * b * c;
  int y = (a + b) * c;
  int z = a * (b + c);
  int i = a + b + c;
  int r = std::max(x, y);
  r = std::max(r, z);
  r = std::max(r, i);
  cout << r << "\n";

  return 0;
}
