#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> list {3, 4, 5, 6, 7, 6};
	multimap<int, int> m;
	for (int i = 0; i < (int) list.size(); i++) {
		int n = list[i];
		m.insert(pair<int, int> (n, i));
	}
	for (auto it = m.begin() ; it != m.end(); it++) {
		cout << it->first << " and " << it->second << "\n";
	}
	return 0;
}
