#include <bits/stdc++.h>

using namespace std;

long long dp[1000];

long long fib(int n) {
	if (dp[n] == 0)
		dp[n] = fib(n - 1) + fib(n - 2);
	return dp[n];
}
int main() {
	long long nax = 4000000;
	dp[1] = 1;
	dp[2] = 2;
	long long s = 0;
	int i = 1;
	while (i++) {
		int v = fib(i);
		if (v > nax) {
			cout << "stop\n";
			break;
		} else {
			if ( v % 2 == 0 )
				s += v;
			cout << v << "\n";
		}
	}
	cout << "Sum 2n terms = " << s; 
	return 0;
}
