/*
1456. Maximum Number of Vowels in a Substring of Given Length
Medium

Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.

Example 5:

Input: s = "tryhard", k = 4
Output: 1

Constraints:

    1 <= s.length <= 10^5
    s consists of lowercase English letters.
    1 <= k <= s.length

*/
class Solution {
public:
    const set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    int isVowel(char c) {
        return vowels.find(c) != vowels.end() ? 1 : 0; 
    }
    int maxVowels(string s, int k) {
        int l = (int) s.size();

        int best_count = 0;
        if ( l < k ) return 0;

        int pref[l];
        pref[0] = isVowel(s[0]);
        for (int i = 1; i < l; i++)
            pref[i] = pref[i-1] + isVowel(s[i]);

        for (int i = 0; i < l; i++) {
            int t = k - 1;
            if ( i + t == l )
                return best_count;
            int count = pref[i + t] - pref[i] + isVowel(s[i]);
            best_count = max(count, best_count);
        }
        return best_count;
    }
};