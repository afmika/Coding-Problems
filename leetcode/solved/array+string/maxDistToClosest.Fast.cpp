class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = seats.size();
        int dist = INT_MIN, dist_left = INT_MIN, dist_right = INT_MIN;
        bool stop_left = false, stop_right = false;
        
        int last = 0;
        for (int i = 0, j = l - 1; i < l; ++i, j--) {
            stop_left  |= seats[i];
            stop_right |= seats[j];
            
            if ( seats[i] ) {
                int count = (i - last + 1 - seats[last] ) / 2;
                dist = max(dist, count);             
                last = i;
            }
            
            if ( !stop_left ) {
                if ( dist_left == INT_MIN ) dist_left = 0;
                dist_left++;
            }
            if ( !stop_right ) {
                if ( dist_right == INT_MIN ) dist_right = 0;
                dist_right++;
            }
        }
        return max({dist_left, dist_right, dist});
    }
};