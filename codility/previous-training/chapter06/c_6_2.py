
def solution(A):
    N = len(A)
    B = [[-1,-1] for i in range(N)]

    _dict, _cnt, _pos = {}, 0, -1
    for i in range(N):
        if not _dict.has_key(A[i]):
            _dict[A[i]] = 1
        else:
            _dict[A[i]] += 1
        if _dict[A[i]] > _cnt:
            _cnt = _dict[A[i]]
            _pos = i
        if _cnt > (i+1)/2:
            B[i][0] = _pos
    
    _dict, _cnt, _pos = {}, 0, -1
    for i in range(N-1, 0, -1):
        if not _dict.has_key(A[i]):
            _dict[A[i]] = 1
        else:
            _dict[A[i]] += 1
        if _dict[A[i]] > _cnt:
            _cnt = _dict[A[i]]
            _pos = i
        if _cnt > (N-i)/2:
            B[i-1][1] = _pos

    #print B
    answer = 0
    for el in B:
        if el[0] == -1 or el[1] == -1:
            continue
        if A[el[0]] == A[el[1]]:
            answer += 1
    return answer


if __name__ == "__main__":
    A = [4, 3, 4, 4, 4, 2]
    print solution(A)
