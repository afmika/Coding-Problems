class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> dp;
        int l = s.size();
        
        for (int i = 0; i < l; i++) {
            if ( i + 10 <= l ) {
                string p = s.substr(i, 10);
                if ( dp.find(p) == dp.end() ) {
                    regex pattern(p);
                    auto it = sregex_iterator(s.begin(), s.end(), pattern);
                    auto end = sregex_iterator();
                    
                    int s_match = 0;
                    for(; it != end; ++it, s_match++);   
                    dp[p] = s_match;
                } else {
                    dp[p]++;                    
                }
            }
        }
        
        vector<string> result;
        for (auto res : dp) {
            if (res.second > 1)
                result.push_back(res.first);
        }

        return result;
    }
};