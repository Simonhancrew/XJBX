from typing import List
from collections import defaultdict
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        freq = defaultdict(int)
        for word in words:
            mask = 0
            for char in word:
                mask |= (1 << (ord(char) - ord('a')))
            freq[mask] += 1
        
        ans = list()
        
        for puzzle in puzzles:
            mask = 0
            total = 0
            for char in puzzle:
                mask |= (1 << (ord(char) - ord("a")))
            subset = mask
            while subset != 0:
                if 1 << (ord(puzzle[0]) - ord('a')) & subset != 0:
                    if subset in freq:
                        total += freq[subset]
                subset = (subset - 1) & mask
            ans.append(total)
            
        return ans