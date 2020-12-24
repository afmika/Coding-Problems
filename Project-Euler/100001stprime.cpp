/*
 

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

 * */

#include <bits/stdc++.h>

using namespace std;


bool isPrime (int n) {
	assert(n > 0);
	if ( n == 2 )
		return true;
	int count = 0;
	for (int i = 1, nax = sqrt((double) n); i <= nax; i++) {
		if (n % i == 0)
			count++;
		if ( count >= 2 )
			return false;
	}
	return true;
}

int nthPrime(int n) {
	assert(n > 0);
	int c = 0, cur = 2;
	while ( c < n ) {
		if ( isPrime(cur++) ) c++;
	}
	return -1 + cur;
}
int main() {
	cout << nthPrime(1) << "\n";
	cout << nthPrime(2) << "\n";
	cout << nthPrime(3) << "\n";
	cout << nthPrime(5) << "\n";
	cout << nthPrime(10001) << "\n";
	return 0;
}
