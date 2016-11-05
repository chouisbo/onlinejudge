package com.ict.golaxy;

import com.ict.golaxy.LRUCache;
import org.junit.Assert;
import org.junit.Test;
import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

public class LRUCacheTest {

    @Test
    public void test01() {
        // Input: 1,[set(2,1),get(2),set(3,2),get(2),get(3)]
        // Expected: [1,-1,2]
        LRUCache cache = new LRUCache(1);
        final List<Integer> Expected = Arrays.asList(1, -1, 2);
        List<Integer> rsList = new LinkedList<>();
        cache.set(2, 1);
        rsList.add(cache.get(2));
        cache.set(3, 2);
        rsList.add(cache.get(2));
        rsList.add(cache.get(3));
        Assert.assertEquals(Expected, rsList);
    }

    @Test
    public void test02() {
        // Input: 2,[set(2,1),set(2,2),get(2),set(1,1),set(4,1),get(2)]
        // Expected: [2,-1]
        LRUCache cache = new LRUCache(2);
        final List<Integer> Expected = Arrays.asList(2, -1);
        List<Integer> rsList = new LinkedList<>();
        cache.set(2, 1); cache.set(2, 2);
        rsList.add(cache.get(2));
        cache.set(1, 1); cache.set(4, 1);
        rsList.add(cache.get(2));
        Assert.assertEquals(Expected, rsList);
    }

    @Test
    public void test03() {
        // Input: 2,[get(2),set(2,6),get(1),set(1,5),set(1,2),get(1),get(2)]
        // Expected: [-1,-1,2,6]
        LRUCache cache = new LRUCache(2);
        final List<Integer> Expected = Arrays.asList(-1, -1, 2, 6);
        List<Integer> rsList = new LinkedList<>();
        rsList.add(cache.get(2));
        cache.set(2, 6);
        rsList.add(cache.get(1));
        cache.set(1, 5);
        cache.set(1, 2);
        rsList.add(cache.get(1));
        rsList.add(cache.get(2));
        Assert.assertEquals(Expected, rsList);
    }

    @Test
    public void test04() {
        // Input: 2,[set(2,1),set(1,1),set(2,3),set(4,1),get(1),get(2)]
        // Expected: [-1,3]
        LRUCache cache = new LRUCache(2);
        final List<Integer> Expected = Arrays.asList(-1, 3);
        List<Integer> rsList = new LinkedList<>();
        cache.set(2, 1);
        cache.set(1, 1);
        cache.set(2, 3);
        cache.set(4, 1);
        rsList.add(cache.get(1));
        rsList.add(cache.get(2));
        Assert.assertEquals(Expected, rsList);
    }

}
