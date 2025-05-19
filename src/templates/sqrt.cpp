
#include <iostream>
using namespace std;
int sqrt_(int x) {
	int l= 1, r=  (x/2);
	int res = 0;
	while (l<r) {
		int m = l + (r-l)/2;
		long long s = m*m;
		if (s == x)
			return m;
		if (s > x)
			r = m-1;
		else
			res = m;
			l = m+1;
	}
	
	return res;
}


int main() {
	int v = sqrt_(10);
	float r = sqrt(10);
	cout << v  << endl;
	cout << r << endl;
	return 0;
}