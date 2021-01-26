from typing import List
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        num = [0] * 100 
        ans = 0
        for it in dominoes:
            val = 0
            if it[0] > it[1]:
                val = it[1] * 10 + it[0]
            else:
                val = it[0] * 10 + it[1]
            ans += num[val]
            num[val] += 1
        return ans
             
# import collections
# class Solution:
#     def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
#         mp = collections.defaultdict(int)
#         ans = 0
#         for it in dominoes:
#             val = 0
#             if it[0] < it[1]:
#                 val = it[0] * 10 + it[1]
#             else:
#                 val = it[1] * 10 + it[0]
#             ans += mp[val]
#             mp[val] += 1
#         return ans