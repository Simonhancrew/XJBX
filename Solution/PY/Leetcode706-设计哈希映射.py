class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.base = 769
        self.data = [[] for _ in range(self.base)]


    def hash(self,key):
        return key % self.base


    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        h = self.hash(key)
        for ii in self.data[h]:
            if ii[0] == key:
                ii[1] = value
                return
        self.data[h].append([key,value])


    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        h = self.hash(key)
        for ii in self.data[h]:
            if ii[0] == key:
                return ii[1]
        return -1



    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        h = self.hash(key)
        for i,ii in enumerate(self.data[h]):
            if ii[0] == key:
                self.data[h].pop(i)
                #py这里可以不return
                return 