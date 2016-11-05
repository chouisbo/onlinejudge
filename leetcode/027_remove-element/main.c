int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int j = numsSize-1;
    while (1) {
        while (j >= i && nums[j] == val) j--;
        while (j >= i && nums[i] != val) i++;
        if (j < i) break;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    return i;
}
