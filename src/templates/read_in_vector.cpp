/**
 * author: Aryan Suri
 * licence: MIT
 **/
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int64_t> A(n);
  for (auto &a : A) {
    cin >> a;
  }
  // or
  for (size_t i = 0; i < n; ++i) {
    cin >> A[i];
  }
  return 0;
}
