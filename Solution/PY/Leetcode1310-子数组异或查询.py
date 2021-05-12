from typing import List
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        arr.append(0)
        for i in range(1,n + 1):
            arr[i] ^= arr[i - 1] 
        arr.insert(0,0)
        ans = []
        for query in queries:
            tmp = arr[query[1] + 1] ^ arr[query[0]]
            ans.append(tmp)
        return ans