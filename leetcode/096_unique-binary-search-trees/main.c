int numTrees(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int *nums = (int *) calloc(n+1, sizeof(int));
    nums[0] = 1;
    nums[1] = 1;
    for (int i=2; i <= n; i++) {
        for (int j=0; j < i; j++) {
            nums[i] += nums[j] * nums[i-j-1];
        }
    }
    int rs = nums[n];
    free(nums);
    return rs;
}
