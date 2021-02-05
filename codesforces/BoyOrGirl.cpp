#include <bits/stdc++.h>

using namespace std;

int main () {
	string input;
	cin >> input;
	int n = 0;
	unordered_map<char, int> m;
	for (char c : input) {
		if (m.find(c) == m.end()) n++;
		m[c]++;
	}
	cout << (n % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
	return 0;
}