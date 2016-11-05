/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var numsMap = {};
    var i, j, k;
    for (i=0; i<nums.length; i++) {
        if (numsMap[nums[i]] === undefined) {
            numsMap[nums[i]] = [];
        }
        numsMap[nums[i]].push(i);
    }

    for (i=0; i<nums.length; i++) {
        var remains = target - nums[i];
        if (numsMap[remains] !== undefined) {
            jList = numsMap[remains];
            for (k=0; k < jList.length; k++) {
                j = jList[k];
                if (i < j) {
                    return [i+1, j+1];
                }
                if (j < i) {
                    return [j+1, i+1];
                }
            }
        }
    }

    return [-1, -1];
};

console.log(twoSum([3,2,4], 6));
