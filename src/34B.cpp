#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m; cin >> n >> m;
  vector<int> T(n);
  for (int &t: T) {
	  cin >> t;
  }
  sort(T.begin(), T.end());
  int s=0;
  for (int i =0; i<m;++i){
	  int t = s+T[i];
	  if (t < s) {
		  s = t;
	  } else {
		  break;
	  }
  }
  cout << abs(s);
  return 0;
}
