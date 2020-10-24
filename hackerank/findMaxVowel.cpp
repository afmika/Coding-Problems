#include <bits/stdc++.h>

using namespace std;


const set<char> vowels {'a', 'e', 'i', 'o', 'u'};
int isVowel(char c) {
    return vowels.find(c) != vowels.end() ? 1 : 0; 
}
/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string findSubstring(string s, int k) {
    int l = (int) s.size();

    string best = "Not found!";
    int best_count = 0;
    if ( l < k ) return best;

    int pref[l];
    pref[0] = isVowel(s[0]);
    for (int i = 1; i < l; i++)
        pref[i] = pref[i-1] + isVowel(s[i]);
        
    for (int i = 0; i < l; i++) {
        int t = k - 1;
        if ( i + t == l )
            return best;
        int count = pref[i + t] - pref[i] + isVowel(s[i]);
        if ( best_count < count ) {
            best = s.substr(i, k);
            best_count = count;
        }
    }
    return best;
}

int main() {
	string input = "azerdii";
	int k = 5;
	cout << findSubstring(input, k);
	return 0;
}