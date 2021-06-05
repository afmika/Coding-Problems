/**
 * @author afmika
 */
 
#include <bits/stdc++.h>

using namespace std;

string makeSmall (string q) {
	string out = "";
	for (char c : q) {
		// we set the 7th bit to 0
		out += (c & 0b1011111) - 'A' + 'a';
	}
	return out;
}

int main () {
	string s = makeSmall ("Hello world");
	cout << s << "\n";
	return 0;
}