import java.util.List;
import java.util.HashMap;
import java.util.Collections;
import java.util.stream.Collectors;
import java.util.Map.Entry;


public class Solution {

    public int[] findMode(TreeNode root) {
        if (null == root) return new int[0];
        HashMap<Integer, Integer> counts = new HashMap<>();
        tranverse(root, counts);
        int maxn = Collections.max(counts.values());
        List<Integer> rsList = counts.entrySet().parallelStream()
                                     .filter(entry -> entry.getValue() == maxn)
                                     .map(entry -> entry.getKey())
                                     .collect(Collectors.toList());
        int[] rs = new int[rsList.size()];
        int i = 0;
        for (Integer x : rsList) rs[i++] = x;
        return rs;
    }

    private void tranverse(TreeNode root, HashMap<Integer, Integer> counts) {
        if (null == root) return;
        tranverse(root.left, counts);
        tranverse(root.right, counts);
        int count = counts.getOrDefault(root.val, 0);
        counts.put(root.val, count+1);
    }

    public static void outputArray(int[] array) {
        System.out.print("[");
        for (int x : array) System.out.print(x + ", ");
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        outputArray(s.findMode(null));
        outputArray(s.findMode(new TreeNode(2147483647)));
    }

}