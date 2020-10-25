class Solution {
public:
    const int MAX_SCORE = 10e7;
    unordered_map<int, int> dp_max;
    unordered_map<int, int> dp_min;
    int minmax(int n, int depth, bool isMax) {
        
        if ( dp_max.find(n) != dp_max.end() && isMax  ) return dp_max[n];
        if ( dp_min.find(n) != dp_min.end() && !isMax ) return dp_min[n];
        
        if ( n <= 0 ) {
            int score = 0;
            if ( n == 0 ) {
                bool alice_won = depth % 2 == 1;
                score = (MAX_SCORE - depth) * (alice_won ? 1 : -1);
                return score;
            }
            return score;
        }
            
		int score = isMax ? INT_MIN : INT_MAX;
        for (int k = sqrt(n); k >= 1; k-- ) {
            int new_n = n - k * k;
            if ( isMax )
                score = max(score, minmax(new_n, depth + 1, false));
            else
                score = min(score, minmax(new_n, depth + 1, true));
        }
        
        if (  isMax ) dp_max[n] = score;
        if ( !isMax ) dp_min[n] = score;
        
        return score;
    }
    
    bool winnerSquareGame(int n) {
        for (int k = sqrt(n); k >= 1; k-- ) {
            int new_n = n - k*k;
            int score = minmax(new_n, 1, false);
            if ( score > 0 ) return true;
        }
        return false; 
    }
};