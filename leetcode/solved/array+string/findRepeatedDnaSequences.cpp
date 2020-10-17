#include <bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	
	unordered_map<string, int> count;
	vector<string> result;
	
	int l = s.size();
	
	for (int i = 0; i < l; i++) {
		if ( i + 10 <= l ) {
			string token = s.substr(i, 10);
			
			if ( count[token] >= 0 )
				count[token]++;
			
			if ( count[token] > 1 ) {
				result.push_back(token);
				count[token] = -1;
			}
		}
	}
	
	return result;
}

int main() {
	string input = "AAGTCTAAAAGAATGGGCAGAGTTGCTCTGCAGCTAAAAAAAAAAAAAAAAAAAAAGCTAAAAAAAAAAAA";
	cout << findRepeatedDnaSequences(input).size() << "\n";
	return 0;
}
