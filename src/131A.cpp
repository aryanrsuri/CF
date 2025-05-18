/**
 * author: Aryan Suri
 * date: 2025-05-17T14:39:22-700
 * licence: MIT
 **/
#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  bool D = 1;
  cin >> S;
  for (size_t i = 1; i < S.size(); ++i) {
    if (S[i] > 96) {
      D = false;
      break;
    }
  }
  if (D) {
    for (size_t i = 0; i < S.size(); ++i) {
      if (S[i] > 96) {
        S[i] -= 32;
      } else {
        S[i] += 32;
      }
    }
  }

  cout << S;
  return 0;
}
