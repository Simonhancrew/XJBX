class Solution:
    def __init__(self):
        self.tail = None
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = TreeNode(-1)
        self.tail = dummy
        def dfs(root):
            if root == None:
                return 
            dfs(root.left)
            root.left = None
            self.tail.right = root
            self.tail = root
            dfs(root.right)
        dfs(root)
        return dummy.right