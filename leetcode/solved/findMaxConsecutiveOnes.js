/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let consec_count = 0;
    let max = -1;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] == 1) {
            consec_count++;
        } else {
            consec_count = 0;
        }
        max = consec_count < max ? max : consec_count;
    }
    return max;
};

console.log( findMaxConsecutiveOnes( [1,1,1,1,0,0,1,1] ) );