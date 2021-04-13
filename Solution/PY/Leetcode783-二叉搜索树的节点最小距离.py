class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.ans = int(2e9)
        self.pre = 0
        self.first = True
    def dfs(self,root):
        if not root:
            return 
        self.dfs(root.left)
        if not self.first:
            self.ans = min(self.ans,root.val - self.pre)
        self.first = False
        self.pre = root.val
        self.dfs(root.right)
    def minDiffInBST(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.ans