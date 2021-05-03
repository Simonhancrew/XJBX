class Solution:
    def reverse(self, x: int) -> int:   
        res = 0
        INT_MIN,INT_MAX = -2 ** 31,2 ** 31 - 1
        while x != 0:
            if res > INT_MAX // 10 or res < INT_MIN // 10 + 1:
                return 0
            #py的取模运算在负数的时候也会返回一个[0,9)之间的数
            #要特判一下
            digi = x % 10
            if x < 0 and digi > 0:
                digi -= 10
            res = res * 10 + digi
            # 负数的时候会向下取更小的
            x = (x - digi) // 10
        return res