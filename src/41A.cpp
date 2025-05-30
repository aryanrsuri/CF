#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ar array
#define vi vector<int>

int32_t main() 
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
	string f,s;
	cin >> f >> s;
	reverse(f.begin(), f.end());
	string ans = (f==s) ? "YES" : "NO";
	cout << ans << '\n';
        
        return 0;
}
