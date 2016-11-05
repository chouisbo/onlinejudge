/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    if (nums.length <=0 ) return;
    var i=0, j=0;
    while (j < nums.length) {
        if (0 === nums[j]) {
            j++;
        } else {
            nums[i++] = nums[j++];
        }
    }
    while (i < nums.length) {
        nums[i++] = 0;
    }
};
