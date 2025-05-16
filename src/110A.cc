#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  long long l = 0;
  int s = 0, c = 0;
  cin >> n;
  while (n > 0) {
    if (n % 10 == 4 || n % 10 == 7) {
      ++l;
    }
    n /= 10;
  }

  if (l == 0) {
    cout << "NO";
    return 0;
  }

  while (l > 0) {
    if (l % 10 == 4 || l % 10 == 7) {
      ++c;
    }

    l /= 10;
    ++s;
  }

  if (s == c) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
