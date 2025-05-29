#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
	  int n; cin >> n;
	  int sum=0,ans=0;
	  // You know there is equal number of open and closed
	  // So on an open paren you can depr the sum and on closed incr
	  // If sum < 0 you need to do a move op to rearrange that open 
	  for (int i = 0; i < n; ++i) {
		  char x;
		  cin >> x;
		  if (x == '(') {
			  ++sum;
		  } else {
			  --sum;
			  if (sum < 0) {
				  sum=0;
				  ++ans;
			  }

		  }
	  }
	  cout << ans << endl;
  }

  return 0;
}
