#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, max_names;
	cin >> n >> max_names;
	long long output[n];
	long long prec = 0, cur = 0;
	for (int d = 0; d < n; d++ ) {
		long long input;
		cin >> input;
		cur = input + prec;
		int p = 0;
		if (d == 1) {
			p = cur / max_names;
		} else {
			p = cur / max_names - prec / max_names;
		}
		prec = cur;
		output[d] = p;
	}
	for (int i = 0; i < n; i++)
		cout << output[i] << (i + 1 < n ? " " : "");
	return 0;
}
