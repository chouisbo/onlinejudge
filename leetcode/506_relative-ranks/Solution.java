public class Solution {

    public String[] findRelativeRanks(int[] nums) {

        Integer[] index = new Integer[nums.length];
        for (int i=0; i<nums.length; i++) index[i] = i;

        Arrays.sort(index, (a, b) -> (nums[b] - nums[a]));

        String[] result = new String[nums.length];
        for (int i=3; i<nums.length; i++) {
            result[index[i]] = String.valueOf(i+1);
        }

        if (nums.length > 0) result[index[0]] = "Gold Medal";
        if (nums.length > 1) result[index[1]] = "Silver Medal";
        if (nums.length > 2) result[index[2]] = "Bronze Medal";

        return result;
    }

}

