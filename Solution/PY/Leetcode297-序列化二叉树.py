class Codec:
    def __init__(self):
        self.u = [0]
        self.ans = ''
    def serialize(self, root):
        def dfs_s(root):
            if root == None:
                self.ans += '#,'
                return
            self.ans += str(root.val) + ','
            dfs_s(root.left)
            dfs_s(root.right)
       
        dfs_s(root)
        return self.ans  
        
    def deserialize(self, data):
        data = data.split(',')
        def dfs_d(data,idx):
            if data[idx[0]] == '#':
                idx[0] += 1
                return None
            node = TreeNode(int(data[idx[0]]))
            idx[0] += 1
            node.left = dfs_d(data,idx)
            node.right = dfs_d(data,idx)
            return node
        res = dfs_d(data,self.u)
        return res