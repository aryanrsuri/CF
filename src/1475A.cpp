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
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
    	if ((n & (n-1)) == 0) {
    		cout << "NO" << endl;
    	} else {
    		cout << "YES" << endl;
    	}
    }
    return 0;
}