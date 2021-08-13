#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/problem/112/A
int unoffset (char v) {
    return ((int) v) - ((int) (v >= 'a' ? 'a' : 'A'));
}

int main () {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0, s = a.size(); i < s; i++) {
	    int diff = unoffset (a[i]) - unoffset (b[i]);
	    if  (diff != 0) {
	        cout << diff / abs(diff);
	        return 0;
	    }
	}
	cout << 0;
	return 0;
}