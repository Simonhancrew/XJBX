from typing import List
## 假设这个最后的结果为ans，ai ^ aj = x,x ^ ai = aj
## 确定x的每一位是否可以为1，可以用一个集合记录所有数前k位，看看有没有合适的x的前k位异或上这个集合中的数还在这个集合中
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ans = 0
        for i in range(30,-1,-1):
            st = set()
            for num in nums:
                st.add(num >> i)
            
            nex = ans * 2 + 1
            fd = False

            for num in st:
                if nex ^ num in st:
                    fd = True
                    break
            if fd:
                ans = nex
            else:
                ans = 2 * ans
        return ans