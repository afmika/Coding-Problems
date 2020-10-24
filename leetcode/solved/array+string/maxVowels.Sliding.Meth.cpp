class Solution {
public:
    const set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    int isVowel(char c) {
        return vowels.find(c) != vowels.end() ? 1 : 0; 
    }
    int countVowel(string s) {
        int count = 0;
        for (char c : s)
            count += isVowel(c);
        return count;
    }
    // sliding window this time ;)
    int maxVowels(string s, int k) {
        int l = (int) s.size();

        if ( l < k ) return 0;
        
        int count = countVowel(s.substr(0, k));
        int best = count;
        
        for (int i = 1; i < l; i++) {
            if ( i + k - 1 == l )
                return best;
            count += isVowel(s[i + k - 1]); // new
            count -= isVowel(s[i - 1]); // where prev began if vowel
            best = max(best, count);
        }
        return best;
    }
};