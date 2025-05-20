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
    for (int &a: A) {
    	cin >> a;
    }

    sort(A.begin(), A.end());
    int ma=INT_MAX, c=0;
    for (int i = 1; i < m-n; i++) {
    	ma = min(ma, A[n+i-1] - A[i]); 
    }
    cout << ma << endl;
    return 0;
}