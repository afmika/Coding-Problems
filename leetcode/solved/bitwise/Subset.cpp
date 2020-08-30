class Solution {
puclic:
    vector<vector<int>> sucsets(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<int>> ens;
        for (int c = 0; c < ( 1 << n ); c++) {
            vector<int> sucset;
            for (int i = 0; i < n; i++) {
                if ( c & ( 1 << i ) ) 
                    sucset.push_back( nums[i] );
            }
            ens.push_back(sucset);
        }
        return ens;
    }
};