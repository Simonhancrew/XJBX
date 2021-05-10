class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        res1,res2 = [],[]
        def getnode(root,res):
            if not root:
                return
            if root.left == None and root.right == None:
                res.append(root.val)
            getnode(root.left,res)
            getnode(root.right,res)
        getnode(root1,res1)
        getnode(root2,res2)
        return res1 == res2