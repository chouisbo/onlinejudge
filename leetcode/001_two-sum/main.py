

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        numsMap = {}
        for i in range(len(nums)):
            if not numsMap.has_key(nums[i]):
                numsMap[nums[i]] = []
            numsMap[nums[i]].append(i)

        for j in range(len(nums)):
            remains = target - nums[j];
            if numsMap.has_key(remains):
                for i in numsMap[remains]:
                    if i < j:   return [i+1, j+1]
                    elif j < i: return [j+1, i+1]
        return [-1, -1]

if __name__ == "__main__":
    s = Solution();
    print s.twoSum([3,3,2,4], 6)