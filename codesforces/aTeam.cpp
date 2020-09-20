#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int tot = 0;
	while ( n-- ) {
		int a , b, c;
		cin >> a >> b >> c;
		tot += (int) ((a + b + c) >= 2);
	}
	cout << tot;
	return 0;
}
