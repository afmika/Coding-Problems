#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/problemset/problem/266/A
int main () {
    int n;
    string s;
    cin >> n >> s;
    int t = 0;
    for (int i = 1; i < n; i++)
        if (s[i - 1] == s[i]) t++;
    cout << t;
	return 0;
}