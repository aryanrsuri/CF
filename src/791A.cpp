#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, y = 0;
  cin >> a >> b;
  while (a <= b) {
    a *= 3;
    b *= 2;
    ++y;
  }

  cout << y;

  return 0;
}
