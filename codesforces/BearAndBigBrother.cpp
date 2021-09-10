#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/791/A
int main () {
	double a, b;
	cin >> a >> b;
	// A = 3^t * a
	// B = 2^t * b
	// A > B = 3^t a > 2^t b => t > ?
	// exp(t ln 3) / exp(t ln 2) > b / a
	// exp(t(ln 3/2)) > b / a
	// t(ln 3/2) > ln(b / a)
	// t > ln(b/a)/ ln 1.5	
	// cout << (a >= b ? 0 : ceil ((log(b / a) / log(1.5))) ) << "\n";
	int years = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		years++;
	}
	cout << years;
	return 0;
}