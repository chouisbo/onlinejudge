
import sys

def bs_le_cnt(A, x, low, high):
    # return the count of A[i] <= x
    # A is ordered by asc
    _start = low
    while low <= high:
        mid = (high - low + 1) / 2 + low
        if A[mid][0] <= x: low = mid + 1
        else: high = mid - 1
    return low - _start

def solution(A):
    N = len(A)
    if N == 0: return 0
    B = []
    for i in range(N):
        B.append((i-A[i], i+A[i]))
    B.sort()
    last_cnt = bs_le_cnt(B, B[0][1], 1, N-1)
    sum = last_cnt
    for i in range(1, N-1):
        if B[i][1] == B[i-1][1]:
            if B[i][0] <= B[i-1][1]:
                last_cnt -= 1
        else:
            last_cnt = bs_le_cnt(B, B[i][1], i+1, N-1)
        sum += last_cnt
        if sum > 10000000: return -1
    return sum

def main(argv):

    #A = [1, 5, 2, 1, 4, 0]
    A = [0] * 500000
    #D = [(0,1), (1,2), (1,2), (1,2), (1,2), (1,2), (2,3)]
    print solution(A)
    
    
    return 0

if __name__ == "__main__":
    main(sys.argv)