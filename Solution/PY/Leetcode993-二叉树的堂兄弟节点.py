class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        xp, xd, fdx = None, None, False
        yp, yd, fdy =  None, None, False
        def check(node,parent,deep):
            if node.val == x:
                nonlocal xp, xd, fdx
                xp,xd,fdx = parent,deep,True
            if node.val == y:
                nonlocal yp, yd, fdy    
                yp, yd, fdy = parent,deep,True
        q = []
        q.append((root,0))
        while q:
            node,deep = q.pop(0)
            if node.left:
                q.append((node.left,deep + 1))
                check(node.left,node,deep+1)
            if node.right:
                q.append((node.right,deep+1))
                check(node.right,node,deep+1)
            if fdx and fdy:
                break
        return xd == yd and xp != yp