int removeDuplicates(int* nums, int numsSize) {
    if (NULL == nums || numsSize <= 0) return 0;
    int i, j, dup;
    const int DUP_MAX = 2;
    for (j=0, i=1, dup=1; i<numsSize; i++) {
        if (nums[i] == nums[j]) {
            if (dup < DUP_MAX) {
                nums[++j] = nums[i];
                dup++;
            }
            continue;
        } else {
            nums[++j] = nums[i];
            dup = 1;
        }
    }
    return j+1; 
}
