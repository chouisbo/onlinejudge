class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row_sets = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')]
        rs = []
        for word in words:
            if len(word) == 0: continue
            for i in xrange(len(row_sets)):
                flag = True
                for c in word.lower(): 
                    if c not in row_sets[i]:
                        flag = False
                        break
                if flag:
                    rs.append(word)
                    break
        return rs
