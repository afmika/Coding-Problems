#include <bits/stdc++.h>
using namespace std;

int main () {
	int k, n, w;
	cin >> k >> n >> w;
	// i*k $ fr the the i-th banana
	// int total = 0;
	// 1*k + 2*k + 3*k + .... w*k
	// k*(1 + 2 + 3 + ... + w) = k*w(w + 1)/2
	// for (int i = 1; i <= w; i++) {
		// int cost = i * k;
		// total += cost;
	// }
	// 1*k + 2*k + 3*k + .... + w*k = k*w(n + 1)/2
	cout << max(0, k * w * (w + 1) / 2 - n);
	return 0;
}