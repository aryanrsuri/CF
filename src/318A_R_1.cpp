#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, x;
  cin >> n >> x;
  if (x % 2 == 0) {
    cout << n - (x / 2);
  } else {
    cout << (x + (n + 1)) / 2;
  }
  return 0;
}
