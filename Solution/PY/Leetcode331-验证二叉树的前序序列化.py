class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        n = len(preorder)
        i = 0
        stk = [1]
        while i < n:
            if not stk:
                return False
            if preorder[i] == ',':
                i += 1
            elif preorder[i] == '#':
                stk[-1] -= 1
                if stk[-1] == 0:
                    stk.pop()
                i += 1
            else:
                while i < n and preorder[i] != ',':
                    i += 1
                stk[-1] -= 1
                if stk[-1] == 0:
                    stk.pop()
                stk.append(2)
        return not stk