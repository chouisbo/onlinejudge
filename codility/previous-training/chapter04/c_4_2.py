
import sys

def solution(A):
    A.sort()
    for i in range(len(A)-2):
        if A[i] + A[i+1] > A[i+2]:
            return 1
    return 0

def main(argv):

    #A = [10, 2, 5, 1, 8, 20]
    A = [10, 50, -2147483648, -2147483648]
    print solution(A)
    
    return 0

if __name__ == "__main__":
    main(sys.argv)