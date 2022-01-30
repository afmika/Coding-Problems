#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/791/A
int main () {
	double a, b;
	cin >> a >> b;
	int years = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		years++;
	}
	cout << years;
	return 0;
}