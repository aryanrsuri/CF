#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  if (k <= (n + 1) / 2) {
    cout << 2 * k - 1;
  } else {
    k -= (n + 1) / 2;
    cout << 2 * k;
  }

  return 0;
}
