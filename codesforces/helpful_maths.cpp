#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/problem/339/A
int main () {
	string str;
	vector<int> values;
	getline(cin, str);
	str += "+";
	string curr = "";
	for (char c : str) {
		if (c == '+') {
			values.push_back(stoi(curr));
			curr = "";
		} else curr += c;
	}
	sort (values.begin(), values.end());
	for (int i = 0, s = values.begin(); i < s; i++) {
		cout << values[i];
		if (i + 1 < s)
			cout << "+";
	}
	return 0;
}