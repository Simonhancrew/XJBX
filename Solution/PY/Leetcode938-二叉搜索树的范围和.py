class Solution:
    def __init__(self):
        self.res = 0
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def dfs(root):
            if not root:
                return
            dfs(root.left)
            if root.val <= high and root.val >= low:
                self.res += root.val
            dfs(root.right)
        dfs(root)
        return self.res