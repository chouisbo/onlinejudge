
import sys

def solution(A):
    B = [ (0.0, 0) for i in range(len(A)) ]
    B[1] = ( (A[1]+A[0])/2.0, 2 )
    _min, j = B[1], 1

    for i in range(2, len(A)):
        curSliceAvg = (A[i-1] + A[i])/2.0
        prefixSliceAvg = (B[i-1][0]*B[i-1][1]+A[i]) / (B[i-1][1]+1)
        if curSliceAvg < prefixSliceAvg:
            B[i] = (curSliceAvg, 2)
        else:
            B[i] = (prefixSliceAvg, B[i-1][1]+1)
        if B[i] < _min:
            _min = B[i]
            j = i
    #print j, j-B[j][1]+1, B[j][1]
    return j-B[j][1]+1

def main(argv):

    #A = [4, 2, 2, 5, 1, 5, 8]
    #A = [100, -100, 150, -100]
    A = [100, -100]
    #A = [5, 2, 5, 1, 5, 8]
    print solution(A)
    
    return 0

if __name__ == "__main__":
    main(sys.argv)