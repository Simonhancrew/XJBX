from typing import List
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        mat = ["+", "-", "*", "/"]

        def eval(s):
            b = stk.pop()
            a = stk.pop()
            if s == "+":
                stk.append(a + b)
            elif s == "-":
                stk.append(a - b)
            elif s == "*":
                stk.append(a * b)
            else:
                stk.append(int(a / b))

        for tt in tokens:
            if tt in mat:
                eval(tt)
            else:
                stk.append(int(tt))

        return stk.pop()