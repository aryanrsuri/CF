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
    int n,m;
    cin >> n >> m;
    if (min(n,m) % 2 == 0) { 
    	cout << "Malvika" << endl;
    } else {
    	cout << "Akshat" << endl;
    }
    return 0;
}