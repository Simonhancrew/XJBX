from functools import cmp_to_key
from typing import List
#python3的排序,lstrip()
#无法使用cmp就使用key + lambda
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        s = map(str, nums)
        key = cmp_to_key(lambda x,y: int(y+x)-int(x+y))
        s = sorted(s, key = key)
        res = "".join(s).lstrip('0')
        return res if res != '' else '0'