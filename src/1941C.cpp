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
    int d = 0;
    string s; cin >> s;
    for (size_t i = 0; i <n ; ++i) {
    	if (s.substr(i,3) == "map" || s.substr(i,3) == "pie")  {
    		++d;
    		i+=2;
	    	}
	    }
	    cout << d << endl;
	}
    return 0;
}