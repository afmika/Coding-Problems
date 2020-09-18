#include <bits/stdc++.h>

using namespace std;

unsigned mask = 0b111111; // min mask

string read(int n, bool isHour = false) {
	string res;
	stringstream os;
	os << n;
	os >> res;
	return (n < 10 && !isHour) ? '0' + res : res;
}

// ex 0:61 => 1:01
unsigned adjust(unsigned t) {
	unsigned h = t >> 6;
	unsigned m = t & mask;
	if ( m >= 60) {
		m %= 60;
		h++;
	}
	if ( h >= 12 ) {
		h %= 12; 
	}
	return (h << 6) | m;	
}

string readTime(unsigned current) {
	string hours = read(current >> 6, true); 
	string minutes = read(current & mask, false);
	return hours + ':' + minutes;
}

void solve(set<string>& solutions, unsigned current, int num) {
	if ( num == 0 ) {
		solutions.insert( readTime(current) );
		return;
	}
	for (int i = 0; i < 10; i++ ) {
		unsigned temp = current | (1 << i);
		temp = adjust(temp);
		if ( temp != current ) {
			solve(solutions, temp, num - 1);	
		}
	}
}

vector<string> readBinaryWatch(int num) {
	vector<string> solutions;
	set<string> solution_set;
	solve(solution_set, 0, num);
	for (string s : solution_set) {
		solutions.push_back(s);
	}
	return solutions;
}

int main() {
	unsigned input = 0b0000111101;
	cout << readTime(input) << "\n";
	cout << readTime(adjust(input)); 
	/*
	vector<string> result = readBinaryWatch(3);
	for (string res : result) {
		cout << res << "\n";
	}
	* */
	return 0;
}
