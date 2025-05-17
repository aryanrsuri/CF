#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long m, n, a;
  cin >> m >> n >> a;
  m = (m + a - 1) / a;
  n = (n + a - 1) / a;
  cout << m * n;

  return 0;
}
