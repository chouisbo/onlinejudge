/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */


function ListNode(val) {
    this.val  = val;
    this.next = null;
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var it_l1  = l1, it_l2 = l2;
    var rsListHead = new ListNode(null);
    var it_head = rsListHead;
    var sum, digit, proceed = 0;

    while (it_l1 !== null && it_l2 !== null) {
        sum = it_l1.val + it_l2.val + proceed;
        if (sum < 10) {
            digit = sum;
            proceed = 0;
        } else {
            digit = sum - 10;
            proceed = 1;
        }

        var listNode = new ListNode(digit);
        it_head.next = listNode;
        it_head = listNode;

        it_l1 = it_l1.next;
        it_l2 = it_l2.next;
    }

    while (it_l1 !== null) {
        sum = it_l1.val + proceed;
        if (sum < 10) {
            digit = sum;
            proceed = 0;
        } else {
            digit = sum - 10;
            proceed = 1;
        }

        var listNode = new ListNode(digit);
        it_head.next = listNode;
        it_head = listNode;

        it_l1 = it_l1.next;
    }

    while (it_l2 !== null) {
        sum = it_l2.val + proceed;
        if (sum < 10) {
            digit = sum;
            proceed = 0;
        } else {
            digit = sum - 10;
            proceed = 1;
        }

        var listNode = new ListNode(digit);
        it_head.next = listNode;
        it_head = listNode;

        it_l2 = it_l2.next;
    }

    if (proceed > 0) {
        var listNode = new ListNode(proceed);
        it_head.next = listNode;
        it_head = listNode;
    }

    return rsListHead.next;

};

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

var createLinkedListByArray = function(a) {
    var head = new ListNode(null);
    var it_head = head;

    for (var i=0; i<a.length; i++) {
        var listNode = new ListNode(a[i]);
        it_head.next = listNode;
        it_head = listNode;
    }

    return head.next;
}

var outputLinkedList = function(listHead) {
    var rsStr = "";
    while (listHead !== null) {
        rsStr   += " "+listHead.val+" ->";
        listHead = listHead.next;
    }
    console.log(rsStr);
}

var testcase = function(a1, a2) {
    var l1 = createLinkedListByArray(a1);
    var l2 = createLinkedListByArray(a2);
    outputLinkedList(l1);
    outputLinkedList(l2);
    outputLinkedList(addTwoNumbers(l1, l2));
    console.log("#######################################");
}

// Test cases
// Input:  [2,4,3], [5,6,4]
// Expected:   [7,0,8]
testcase([2,4,3], [5,6,4]);

// Input:  [5], [5]
// Expected:   [0,1]
testcase([5], [5]);

// Input:  [9,1,6], [0]
// Expected:   [9,1,6]
testcase([9,1,6], [0]);






