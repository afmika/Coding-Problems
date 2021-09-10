#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1097/A
using namespace std;
int main () {
    string card;
    string game;
    getline (cin, card);
    getline (cin, game);
    for (int i = 0, s = game.size(); i < s; i += 2) {
        string curr = game.substr(i, 2);
        if (curr[0] == card[0] || curr[1] == card[1]) {
            cout << "YES";
            return 0;
        }
        i++;
    }
    cout << "NO";
	return 0;
}