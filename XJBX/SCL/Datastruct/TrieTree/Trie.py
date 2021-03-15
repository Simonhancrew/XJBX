class TrieNode():
    def __init__(self):
        self.child = [None] * 26
        self.cnt = 0
        self.end = False

class Trie():
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self,string):
        p = self.root

        for i in string:
            if p.child[ord(i) - ord('a')] == None:
                new_node = TrieNode()
                p.child[ord(i) - ord('a')] = new_node
                p = new_node
            else:
                p = p.child[ord(i) - ord('a')] 
        
        p.end = True
        p.cnt += 1

    def query(self,string):
        p = self.root

        for i in string:
            if p.child[ord(i) - ord('a')] == None:
                return 0
            p = p.child[ord(i) - ord('a')]
        if p.end == True:
            return p.cnt
        else:
            return 0
        
if __name__=="__main__":
    tri = Trie()
    tri.insert("str")
    tri.insert("str")
    tri.insert("cncnccncncncnnccncncnccncc")
    tri.insert("str")
    print(tri.query("ncncncnnc"))
    print(tri.query("str"))
    print(tri.query("cncnccncncncnnccncncnccncc"))


'''

class Trie:
    def __init__(self):

        self.root = {}
        self.end = -1
 
    def insert(self, word):
        curNode = self.root
        for c in word:
            if not c in curNode:
                curNode[c] = {}
            curNode = curNode[c]
        curNode[self.end] = True
 
    def search(self, word):
        curNode = self.root
        for c in word:
            if not c in curNode:
                return False
            curNode = curNode[c]
            
        if not self.end in curNode:
            return False
        
        return True
 
    def startsWith(self, prefix):
        curNode = self.root
        for c in prefix:
            if not c in curNode:
                return False
            curNode = curNode[c]
    
'''