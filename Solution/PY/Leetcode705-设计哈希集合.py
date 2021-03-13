#用python去写就简单很多
#list模拟链表，而且可以有in的判断，不用去遍历

class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.base = 769
        self.dt = [[] for _ in range(self.base)]

    def hash(self,key):
        return key % self.base

    def add(self, key: int) -> None:
        h = self.hash(key)
        if key in self.dt[h]:
            return
        self.dt[h].append(key)

    def remove(self, key: int) -> None:
        h = self.hash(key)
        if key not in self.dt[h]:
            return
        self.dt[h].remove(key)

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        h = self.hash(key)
        return key in self.dt[h]
