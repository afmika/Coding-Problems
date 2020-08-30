class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> m;
        for (char c : s) {
            if (m.find(c) == m.end()) { 
                m[c] = 1;        
            } else {
                m[c]++;
            }
        }
        
        for (char c : t) {
            if (m.find(c) == m.end()) {
                return false;
            } else {
                if (m[c] > 0)
                    m[c]--;
                else return false;
            }
        }
        return true;
    }
};