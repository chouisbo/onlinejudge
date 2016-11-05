def solution(A):
    # write your code in Python 2.6
    _dict, _max_freq, pos = {}, 0, -1
    for i in range(len(A)):
        if not _dict.has_key(A[i]):
            _dict[A[i]] = 1
        else:
            _dict[A[i]] += 1
        if _max_freq < _dict[A[i]]:
            _max_freq = _dict[A[i]]
            pos = i
    if _max_freq > len(A) / 2:
        return pos
    else:
        return -1

A = [3, 4, 3, 2, 3, -1, 3, 3]
print solution(A)