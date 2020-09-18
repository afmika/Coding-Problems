#include <bits/stdc++.h>
using namespace std;
map<char, int> cmap;
vector<char> idx;
vector<bool> used;

using namespace std;

void displayMap() {
	for (auto v : cmap) {
		cout << v.first << " : " << v.second << "\n";
	}
	cout << "\n";
}

int compose(string text, map<char, int> m) {
	int ds = 0;
	int size = (int) text.size();
	for (int i = 0; i < size; i++) {
		ds += pow(10, size - i - 1) * m[text[i]];
	}
	return ds;
}

bool equals(vector<string> words, string result) {
	int right_side = 0;
	for (string w : words) {
		right_side += compose(w, cmap);
	}
	// right_side == 0 || left_side == 0 means we mapped 0 more than once
	return right_side != 0 && 0 == (right_side - compose(result, cmap)); 
}

void solve(bool& output, vector<string>& words, string result, int index) {
	if ( equals(words, result) ) {
		output = true;
		return;
	}
	if ( index >= (int) idx.size() ) {
		return;
	}
	for (int n = 0; n <= 9; n++) {
		if ( !used[n] && !output ) { 
			cmap[idx[index]] = n;
			used[n] = true;
			// displayMap();
			solve(output, words, result, index + 1);
			used[n] = false;
		}
	}
}

bool isSolvable(vector<string>& words, string result) {
	for (string w : words) {
		for (char c : w) {
			cmap[c] = 0;
		}
	}
	for (char c : result) {
		cmap[c] = 0;
	}
	
	for (int i = 0; i <= 9; i++)
		used.push_back(false);
	for (auto v : cmap)
		idx.push_back(v.first);
	
	cout << idx.size() << " chars\n";
	bool output = false;
	solve(output, words, result, 0);
	return output;
}

int main() {
	vector<string> words = {"1234", "2468"};
	string result = "4132";
	cout << isSolvable(words, result) << "\n";
	displayMap();	
	return 0;
}
