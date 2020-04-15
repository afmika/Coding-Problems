int findMaxConsecutiveOnes(int* nums, int numsSize){
    int consec_count = 0;
    int max = -1;
    for(size_t i = 0; i < numsSize; i++) {
        if(nums[i] == 1) {
            consec_count++;
        } else {
            consec_count = 0;
        }
        max = consec_count < max ? max : consec_count;
    }
    return max;
}