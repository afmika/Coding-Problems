class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = seats.size();

        int dist = 0, dist_left = 0, dist_right = 0;
        bool stop_left = false, stop_right = false;

        deque<int> occ;        
        for (int i = 0, j = l - 1; i < l; ++i, j--) {
            stop_left  |= seats[i];
            stop_right |= seats[j];
            
            if ( seats[i] ) 
                occ.push_back(i);
            
            if ( !stop_left ) dist_left++;
            if ( !stop_right ) dist_right++;
        }
        
        
        for (int i = 1; i < occ.size(); i++) {
            int left  = occ[i - 1], right = occ[i];
            int count = (right - left + 1 - seats[left] ) / 2;
            dist = max(dist, count);
        }
        
        return max({dist_left, dist_right, dist});
    }
};