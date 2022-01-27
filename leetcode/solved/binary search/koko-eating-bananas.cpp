class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Knowing that 1 <= bananas per hour <= max pile
        int L = 1, 
            R = *max_element(piles.begin(), piles.end());

        int n = (int) piles.size();
        
        while (L < R) {
            int m = (L + R) / 2;
            int time = n;
            for (int pile : piles)
                time += (pile - 1) / m; 
            if (time > h) L = m + 1; 
            else          R = m;
        }
        return R;
    }
};