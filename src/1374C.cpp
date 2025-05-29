#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
	  int n; cin >> n;
	  vector<int> S;
	  for (int i = 0; i < n; ++i) {
		  char x;
		  cin >> x;
		  if (x == ')') {
			  if (S.size() == 0) {
				  continue;
			  }
			  if (S.back() == '(') {
				  S.pop_back();
			  }
		  } else {
			  S.push_back(x);
		  }
	  }
	  cout << S.size() << endl;
  }

  return 0;
}
