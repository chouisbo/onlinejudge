
void reverse(int* array, int len) {
    if (NULL == array || len <= 1) {
        return array;
    }
    int i, j, tmp;
    for (i=0, j=len-1; i<j; i++, j--) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    int r = k % numsSize;
    reverse(nums, numsSize-r);
    reverse(&nums[numsSize-r], r);
    reverse(nums, numsSize);
}
