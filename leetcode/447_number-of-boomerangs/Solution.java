public class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int count = 0;
        int n = points.length;
        for (int i = 0; i < n; i++) {
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int j = 0; j < n; j++) {
                int dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) 
                        + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                if (! map.containsKey(dis)) {
                    map.put(dis, 0);
                }
                // we can swap (j, k)
                count += map.get(dis) * 2;
                map.put(dis, map.get(dis) + 1);
            }
        }
        return count;
    }
}