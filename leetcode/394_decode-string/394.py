# s = "3[a]2[bc]", return "aaabcbc".
# s = "3[a2[c]]", return "accaccacc".
# s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) <= 0: return ""
        num, stack = "", [["", 1]]
        for ch in s:
            if ch.isdigit(): num += ch
            elif ch == '[':
                stack.append(["", int(num)])
                num = ""
            elif ch == ']':
                st, k = stack.pop()
                stack[-1][0] += st * k
            else:
                stack[-1][0] += ch
        return stack[0][0]


if __name__ == "__main__":
    s = Solution()
    print ("aaabcbc", s.decodeString("3[a]2[bc]"))
    print ("accaccacc", s.decodeString("3[a2[c]]"))
    print ("abcabccdcdcdef", s.decodeString("2[abc]3[cd]ef"))
