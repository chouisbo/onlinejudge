int removeDuplicates(int* nums, int numsSize) {
    if (NULL == nums || numsSize <= 0) return 0;
    int i, j;
    for (j=0, i=1; i<numsSize; i++) {
        if (nums[i] == nums[j]) {
            continue;
        } else {
            nums[++j] = nums[i];
        }
    }
    return j+1; 
}
