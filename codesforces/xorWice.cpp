#include <bits/stdc++.h>

using namespace std;

int xorWice (int a, int b) {
	int sm = min (a, b);
	int x = max(sm - 1, 0);
	int c = (a ^ x) + (b ^ x);
	x++;
    return m;
}

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << xorWice (a, b) << "\n";
	}
    return 0;
}