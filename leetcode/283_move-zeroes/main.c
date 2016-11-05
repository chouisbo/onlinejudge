void moveZeroes(int* nums, int numsSize) {
    if (numsSize <=0 ) return;
    int i=0, j=0;
    while (j < numsSize) {
        if (0 == nums[j]) {
            j++;
        } else {
            nums[i++] = nums[j++];
        }
    }
    while (i < numsSize) {
        nums[i++] = 0;
    }
}
