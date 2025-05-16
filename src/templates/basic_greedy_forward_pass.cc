#include <ios>
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string in;
  int next = 0;
  const char *sub = "hello";
  cin >> in;
  for (char c : in) {
    if (sub[next] == c) {
      ++next;
      // >>> REVIEW : Add early break for ^ perf
      if (next == 5)
        break;
      // <<<
    }
  }

  if (next == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
