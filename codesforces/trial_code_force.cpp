#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int res[n];
	int i = 0;
	while (i < n) {
		int a, b;
		cin >> a >> b;
		res[i] = a + b;
		++i;
	}
	
	for (int i = 0; i < n; i++)
		cout << res[i] << '\n';
	return 0;
}

