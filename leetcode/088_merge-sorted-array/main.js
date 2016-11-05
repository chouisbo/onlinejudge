/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    if (n <= 0) return;
    var i, j, k;
    for (i=m-1; i>=0; i--) {
       nums1[n+i] = nums1[i];
    }
    for (i=0, j=n, k=0; i<m+n; i++) {
        if (k >= n) return;
        if (j >= m+n) break;
        if (nums1[j] <= nums2[k]) {
            nums1[i] = nums1[j++];
        } else {
            nums1[i] = nums2[k++];
        }
    }
    while (k<n) {
        nums1[i++] = nums2[k++];
    }
};

