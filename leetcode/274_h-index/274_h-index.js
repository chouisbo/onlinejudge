/**
 * Given an array of citations (each citation is a non-negative integer) of a researcher, 
 * write a function to compute the researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: 
 * "A scientist has index h if h of his/her N papers have at least h citations each, 
 * and the other N − h papers have no more than h citations each."
 * 
 * For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total 
 * and each of them had received 3, 0, 6, 1, 5 citations respectively. 
 * Since the researcher has 3 papers with at least 3 citations each and 
 * the remaining two with no more than 3 citations each, his h-index is 3.
 * 
 * Note: If there are several possible values for h, the maximum one is taken as the h-index.
 * 
 * Hint:
 * 1. An easy approach is to sort the array first.
 * 2. What are the possible values of h-index.
 * 3. A faster approach is to use extra space.
 */


/**
 * @param {number[]} citations
 * @return {number} 
 * 
 * [3, 0, 6, 1, 5] => [0, 1, 3, 5, 6]
 */
var hIndex = function(citations) {
    citations.sort(function(a, b) {
        return a - b;
    });
    // for (i in citations) console.log(citations[i]);
    var len = citations.length;
    for (var idx = len-1; idx >= 0; idx--) {
        if (citations[idx] < len-idx) break;
    }
    return len-idx-1;
};

console.log(hIndex([1,1,3,6,7,10,7,1,8,5,9,1,4,4,3]));
console.log(hIndex([3, 0, 6, 1, 5]));
console.log(hIndex([100]));
console.log(hIndex([1]));
console.log(hIndex([]));

