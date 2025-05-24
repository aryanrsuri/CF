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
    map<string,int> f;
    while (t--) {
	string s;
	cin >> s;
	f[s]++;
    }

    pair<string, int> max_pair = *f.begin();
    for (auto p : f) {
	    if (p.second > max_pair.second) {
		    max_pair = p;
	    } 
    }


    cout << max_pair.first << endl;



    return 0;
}
