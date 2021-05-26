class Solution:
    def reverseParentheses(self, s: str) -> str:
        cur = ""
        n = len(s)
        stk = []
        for i in range(n):
            if s[i] == '(':
                stk.append(cur)
                cur = ""
            elif s[i] == ')':
                cur = cur[::-1]#字符串反转的方法
                cur = stk.pop(-1) + cur
            else:
                cur += s[i]
        return cur