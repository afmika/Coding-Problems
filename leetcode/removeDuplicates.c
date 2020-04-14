int removeDuplicates(int* nums, int numsSize){
	size_t k = 0;
	for(size_t i = 0; i < numsSize; i++) {
		if(i > 0) {
			if(nums[ i - 1 ] != nums[i]) {
				nums[k] = nums[i];
				k++;
			}
		} else {
			k++;
		}
	}
    return k;
}