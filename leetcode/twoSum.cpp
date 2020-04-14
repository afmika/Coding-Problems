class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       /**
        * Bruteforce Optimised
        *       a0    a1    a2    ...   ...     aN
        * a0   a0+a0  ...   ...   ...   ...   a0 + aN
        * a1   ....   ...
        * .    ....   ...  aK+a2  ...  aK+aP     .
        * .      .                               .      
        * .            .                         .
        * aN   aN+a1  ...   ...   ...   ...   aN + aN
        *
        * if the current loop is at index-K then we just only need to care
        * about row,col >= K, K 
        **/
        vector<int> indices(2, 0);
        size_t size = nums.size();
        for(size_t i = 0; i < size; i++) {
            for(size_t j = i+1; j < size; j++) {
                if(nums[i] + nums[j] == target ) {
                    indices[0] = i; indices[1] = j;
                    return indices;
                }
            }
        }
        return indices;
    }
};