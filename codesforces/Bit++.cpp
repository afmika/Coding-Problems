#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int val = 0;
	while (n--) {
		string row;
		cin >> row;
		int sg = 1;
		for (char c : row) {
			if (c == '-') { sg *= -1; break; }
		}
		val += sg;
	}
	cout << val;
	return 0;
}