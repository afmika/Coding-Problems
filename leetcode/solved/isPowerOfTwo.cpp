#include <bits/stdc++.h>
using namespace std;

bool isInteger(double x) {
	return floor(x) == x;
}
bool isPowerOfTwo(int n) {
	if ( n <= 0 ) return false;
	double exponent = log2( n );
	if ( ! isInteger( exponent ) ) {
		return false;
	}
	return true;
}
int main() {
	vector<int> test{1,2,3, -4, 5, 6, -8, 9};
	for (auto a : test) {
		cout << a << " : " << isPowerOfTwo( a ) << endl;
	}
	return 0;
}
