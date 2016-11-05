
int rob(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    if (1 == numsSize) return nums[0];
    if (2 == numsSize) return nums[0] > nums[1] ? nums[0] : nums[1];
    int p_2 = nums[0];
    int p_1 = nums[0] > nums[1] ? nums[0] : nums[1];
    int p;
    for (int i=3; i<=numsSize; i++) {
        if (nums[i-1]+p_2 > p_1) {
            p = nums[i-1]+p_2;
        } else {
            p = p_1;
        }
        p_2 = p_1;
        p_1 = p;
    }
    return p;
}
