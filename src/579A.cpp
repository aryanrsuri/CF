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
    int n; cin >> n;
    int c=0;
    while (n) {
    	n &= n-1;
    	c++;
    }
    cout << c << endl;
    return 0;
}