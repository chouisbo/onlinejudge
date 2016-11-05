
int majorityElement(int* nums, int numsSize) {
    int i, n=nums[0], count;
    for (i=1, count=1; i<numsSize-count; i++) {
        if (count <= 0) {
            n = nums[i];
            count++;
        } else {
            if (n != nums[i]) {
                count--;
            } else {
                count++;
            }
        }
    }
    return n; 
}

