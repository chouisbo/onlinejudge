/*
Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) -
Get the value (will always be positive) of the key if the key exists in the
cache, otherwise return -1.

set(key, value) -
Set or insert the value if the key is not already present. When the cache
reached its capacity, it should invalidate the least recently used item before
inserting a new item.


$ mvn archetype:generate -DgroupId=com.ict.golaxy \
                         -DartifactId=junitdemo \
                         -DarchetypeArtifactId=maven-archetype-quickstart \
                         -DinteractiveMode=false
*/

package com.ict.golaxy;

import java.util.HashMap;

public class LRUCache {
    private HashMap<Integer, DequeNode> knMap; // key-node Map
    private DequeNode head;
    private DequeNode tail;
    private int size;
    private final int CAPACITY;

    public LRUCache(int capacity) {
        knMap = new HashMap<>();
        head = new DequeNode(null, null);
        tail = new DequeNode(null, null);
        head.next = tail; tail.prev = head;
        size = 0; CAPACITY = capacity;
    }

    public int get(int key) {
        DequeNode node = knMap.get(key);
        if (null == node) return -1;
        if (node.next != tail || tail.prev != node) {
            node.next.prev = node.prev;
            node.prev.next = node.next;
            node.prev = tail.prev;
            node.next = tail;
            tail.prev.next = node;
            tail.prev = node;
        }
        return node.val;
    }

    public void set(int key, int value) {
        if (CAPACITY <= 0) return;
        DequeNode node = knMap.get(key);
        if (node != null) {
            node.val = value;
            get(key);
            return;
        }
        if (size >= CAPACITY) {
            int popKey = head.next.KEY;
            head.next.next.prev = head;
            head.next = head.next.next;
            knMap.remove(popKey);
            size--;
        }
        node = new DequeNode(key, value);
        knMap.put(key, node);
        tail.prev.next = node;
        node.prev = tail.prev;
        node.next = tail;
        tail.prev = node;
        size++;
    }

    protected class DequeNode {
        public DequeNode prev;
        public DequeNode next;
        public final Integer KEY;
        public Integer val;
        public DequeNode(Integer key, Integer val) {
            KEY = key; this.val = val;
            prev = null; next = null;
        }
    }
}
