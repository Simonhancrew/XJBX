class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.num = []
        self.k = 0
        self.dfs(nestedList)

    def dfs(self,nestedList):
        for i in nestedList:
            if i.isInteger():
                self.num.append(i.getInteger())
            else:
                self.dfs(i.getList())

    def next(self) -> int:
        out = self.num[self.k]
        self.k += 1
        return out
    
    def hasNext(self) -> bool:
        if self.k < len(self.num):
            return True
        else:
            return False