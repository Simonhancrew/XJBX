class Trie:
    def __init__(self):
        self.isendofword = False
        self.next = [None] * 26

    def insert(self, word: str) -> None:
        node = self
        for ch in word:
            ch = ord(ch) - ord('a')
            if not node.next[ch]:
                node.next[ch] = Trie()
            node = node.next[ch]
        node.isendofword = True 

    def search(self, word: str) -> bool:
        node = self
        for ch in word:
            ch = ord(ch) - ord('a')
            if not node.next[ch]:
                return False
            node = node.next[ch]
        return node.isendofword

    def startsWith(self, prefix: str) -> bool:
        node = self
        for ch in prefix:
            ch = ord(ch) - ord('a')
            if not node.next[ch]:
                return False
            node = node.next[ch]
        return True