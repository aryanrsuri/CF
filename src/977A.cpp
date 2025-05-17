#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  while (k--) {
    if (n % 10 == 0) {
      n = (int)n / 10;
    } else {
      --n;
    }
  }

  cout << n;

  return 0;
}
