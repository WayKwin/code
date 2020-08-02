class Solution(object):
    def simplifyPath(self, path):
        stack = []
        for i in path.split('/'):
            if i not in ['', '.', '..']:
                stack.append(i)
            elif i == '..' and stack:
                stack.pop()
        return "/".join(stack)
if __name__ == "__main__":
    # s = Solution()
    # res = s.simplifyPath("/home/go/src")
    # print(res)