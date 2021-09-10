#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/problemset/problem/281/A
int main () {
	string s, r = "";
	cin >> s;
	for (int i = 0, n = s.size(); i < n; i++) {
		char c = s[i];
		r += (c >= 'a' && i == 0) ? (c - 32) : c;
	}
	cout << r;
	return 0;
}