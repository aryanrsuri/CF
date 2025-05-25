#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k; cin >> k;
	vector<int> A;
	if (k>0) {
		cout << k << endl;
	} else {
		k = -k;
		while (k != 0) {
			A.push_back(k%10);
			k/=10;
		}
		reverse(A.begin(), A.end());
		if (A[A.size()-1] > A[A.size()-2]) {
			A.erase(A.begin()+A.size());
		} else {
			A.erase(A.begin()+A.size()-2);
		}
		if (A.size()==1 && A[0] == 0) {
			cout << 0;
		} 
		else { 
			cout << '-';
			for (int a: A) {
				cout << a ;
			}
		}
		cout << endl;

	}
 


	return 0;
}


