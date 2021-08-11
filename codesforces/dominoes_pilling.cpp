#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/50/A
using namespace std;

int dominoesOptimalCount (int w, int h) {
	if ((w == 1 and h < 2) or (h == 1 and w < 2))
		return 0;
	
	// solve for 1 dim case
	if (h == 1 or w == 1)
		return (h == 1 ? w : h) / 2;

	int total = 0;
	if (h % 2 == 0) {
		// ex : h == 2 ===> we can put 1 on a row
		//      h == 4 ===> we can put 2 on a row
		// # # .... #
		// # # .... #
		// ..........
		// # # .... #
		total += (h / 2) * w;
	} else {
		// h is odd
		// solve for height = 2n case
		int hh = h - 1;
		total += (hh / 2) * w;
		// solve the bottom (1 dim)
		total += w / 2;
	}
	return total;
}

int main () {
	int w, h;
	cin >> w >> h;
	cout << dominoesOptimalCount (w, h);
	return 0;
}