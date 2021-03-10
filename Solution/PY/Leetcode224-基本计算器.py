class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)
        ret = 0
        ops = [1]
        sign = 1
        i = 0
        while i < n:
            if s[i] == ' ':
                i += 1
            elif s[i] == '+':
                sign = ops[-1]
                i += 1
            elif s[i] == '-':
                sign = -ops[-1]
                i += 1
            elif s[i] == '(':
                ops.append(sign)
                i += 1
            elif s[i] == ')':
                ops.pop()
                i += 1
            else:
                sum = 0
                while i < n and s[i] >= '0' and s[i] <= '9':
                    sum = sum * 10 + ord(s[i]) - ord('0')
                    i += 1
                ret += sign * sum
        return ret