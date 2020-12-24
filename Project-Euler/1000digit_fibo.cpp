#include <bits/stdc++.h>
using namespace std;


const double phi = 1.6180339887;


int lengthNum (int n) {
	return log10((double) n) + 1;
}

double fib(int n) {
	return (pow(phi, n) - pow(-phi, -n)) / sqrt(5);
}
/*
 * log A = log10 (p^n - (-p)^n) - 0.5 * log10 5
 * */
double logFib(int n) {
	return log10(pow(phi, n) - pow(-phi, -n));
}

// log10 fib(i) = log10(fibi-1 + fibi-2)

int main() {
	int digitsMax = 3, i = 1;
	while (true) {
		double res = fib(i);
		cout << "i = " << i << " fib(i) = " << res << endl;
		if ( digitsMax == lengthNum(res) ) {
			cout << lengthNum(res) << endl;
			break;
		}
		i++;
	}
	return 0;
}
