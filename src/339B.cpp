/*
 * Author: Aryan Suri
 * Licence: MIT
 * */
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<int> A(m);
    for (int &a:A) {
    	cin >> a;
    }
    int c = A[0]-1;
    for (int i = 1; i < m; ++i) {
    	if (A[i] < A[i-1]) {
    		c += (n - (A[i-1] - A[i]));
    	} else {
    		c += (A[i] - A[i-1]);
    	}
    }
    cout << c << endl;


    return 0;
}