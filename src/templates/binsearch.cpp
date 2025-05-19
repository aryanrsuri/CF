#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
int binsearch(vector<T> A, T t) { 
	size_t L=0, R=A.size()-1;
	while (L <= R) {
		size_t m = L + (R-L)/2;
		if (A[m] == t) return m;
		if (A[m] < t) L = m+1;
		else
			R = m-1;
	}
	return -1;
 }

int main() {
	using T = char;
	vector<T> v = { 1, 2 ,3 ,4};
	cout << binsearch<T>(v, 3) << endl;
	return 0;
}
