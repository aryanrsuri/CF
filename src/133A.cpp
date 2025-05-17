#include <iostream>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;

  cin >> s;
  for (char c : s)
  {
    if (c == 'H' || c == 'Q' || c == '9')
    {
      cout << "YES" << std::endl;
      return 0;
    }
  }
  cout << "NO" << std::endl;

  return 0;
}
