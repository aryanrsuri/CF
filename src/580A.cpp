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
    int m = 1;
    int c = 1;
    vector<int> A(n);
    for (int& a: A)
    {
        cin >> a;
    }

    for (int i = 1; i < n; ++i)
    {
    	if (A[i] >= A[i-1]) {
    		c++;
    		m = max(m,c);
    	} else {
            c = 1;
        }
    }
    cout << m << endl;
    return 0;
}