#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ar array
#define vi vector<int>

int32_t main() 
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
	int n,h; cin >> n >> h;
	int k = n;

	while (n--) {
		int a;
		cin >> a;
		if (a > h)
			k++;
	}
	cout << k << '\n';
        
        return 0;
}
