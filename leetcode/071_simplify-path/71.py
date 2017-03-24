class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for token in path.split('/'):
            if "" == token or "." == token: continue
            if ".." == token: 
                if stack: stack.pop(-1)
                continue
            stack.append(token)
        return "/"+"/".join(stack)
            
            
        

if __name__ == "__main__":
    s = Solution()
    print (s.simplifyPath("/."))
    print (s.simplifyPath("/.."))
    print (s.simplifyPath("/home/"))
    print (s.simplifyPath("/home/chouisbo"))
    print (s.simplifyPath("/a/./b/../../c/"))
