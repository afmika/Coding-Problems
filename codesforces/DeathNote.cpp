#include <bits/stdc++.h>

using namespace std;

int main() {
	
	long long n, max_names;
	cin >> n >> max_names;
	
	long long output[n];
	
	long long prec = 0, S = 0;
	for (int d = 0; d < n; d++ ) {
		long long input;
		cin >> input;
		S = input + prec;
		long long p = 0;
		if (d == 0) {
			p = S / max_names;
		} else {
			p = S / max_names - prec / max_names;
		}
		
		prec = S;
		output[d] = p;

	}
	for (int i = 0; i < n; i++)
		cout << output[i] << (i + 1 < n ? " " : "");
	return 0;
}
