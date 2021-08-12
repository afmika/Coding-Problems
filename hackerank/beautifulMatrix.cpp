#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/problemset/problem/263/A
int main () {
	// manathan dist goes brrr....
	int y, x = 0;
	int cx = 2, cy = 2;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int c = 0;
			cin >> c;
			if (c == 1) {
				// It is guaranteed that the matrix consists of 24 zeroes and a single number one.
				y = i; x = j;
				cout << abs(cx - x) + abs(cy - y);
				return 0;
			}
		}
	}
	return 0;
}