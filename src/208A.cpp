/**
 * author: Aryan Suri
 * licence: MIT
 **/
#include <iostream>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  const string n = "WUB";
  cin  >> s;
  while (s.find(n) != string::npos) {
    size_t i = s.find(n);
    s.replace(i,3," ");
  }
  cout << s << endl;




  return 0;
}

