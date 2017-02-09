import random

class Solution:

    def minDistance(self, word1, word2):
            """
            :type word1: str
            :type word2: str
            :rtype: int
            """
            m, n = len(word2), len(word1)
            d = [[0] * (n+1) for k in range(m+1)]
            for i in range(m+1): d[i][0] = i
            for j in range(n+1): d[0][j] = j
            # self.printMatrix(word1, word2, d)
            for i in range(1, m+1):
                for j in range(1, n+1):
                    if word1[j-1] == word2[i-1]: d[i][j] = d[i-1][j-1]
                    else:
                        d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+1)
                # self.printMatrix(word1, word2, d)
            self.backtrace(word1, word2, d)
            return d[m][n]
    
    def printMatrix(self, word1, word2, matrix):
        print ('$', list('$'+word1))
        word2 = '$' + word2
        for i in range(len(word2)):
            print (word2[i], [str(el) for el in matrix[i]])
        print '-' * 120
    
    def backtrace(self, word1, word2, d):
        m, n, steps = len(word2), len(word1), []
        # generate a random solution
        while m > 0 and n > 0:
            if word2[m-1] == word1[n-1] and d[m][n] == d[m-1][n-1]:
                m -= 1
                n -= 1
            else:
                choices = []
                # 0 - delete word2[m]
                if d[m][n] == d[m-1][n] + 1: choices.append(0)
                # 1 - insert word1[n]
                if d[m][n] == d[m][n-1] + 1: choices.append(1)
                # 2 - substitute word2[m] => word1[n]
                if d[m][n] == d[m-1][n-1] + 1: choices.append(2)
                # randomly choose one possible choices
                rc = random.choice(choices)
                if 0 == rc: 
                    steps.append("delete word2[%d]='%s'" % (m-1, word2[m-1]))
                    # steps.append("delete (m, n) = (%d, %d)" % (m, n))
                    m -= 1
                elif 1 == rc:
                    steps.append("insert word1[%d]='%s' at %d " % (n-1, word1[n-1], m-1))
                    # steps.append("insert (m, n) = (%d, %d)" % (m, n))
                    n -= 1
                elif 2 == rc: 
                    steps.append("substitute word2[%d]='%s' to word1[%d]='%s'" % (m-1, word2[m-1], n-1, word1[n-1]))
                    # steps.append("substitue (m, n) = (%d, %d)" % (m, n))
                    m -= 1
                    n -= 1
                else:
                    print ('Error!')
                    return
        while m > 0:
            steps.append("delete word2[%d]='%s'" % (m-1, word2[m-1]))
            m -= 1
        while n > 0:
            steps.append("insert word1[%d]='%s' at 0" % (n-1, word1[n-1]))
            n -= 1
        steps.reverse()
        for i in range(len(steps)):
            print ("Step %d: %s" % (i+1, steps[i]))


if __name__ == "__main__":
    s = Solution()
    print ("The Edit Distance between '%s' and '%s' is %d" % ("kitten", "sitting", s.minDistance("kitten", "sitting")))
    # print (s.minDistance("ksitten", "sitting"))
    # print (s.minDistance("caat", "cattt"))

