class Solution:
    hh = [
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I"),
    ]

    def intToRoman(self, num: int) -> str:
        res = ""
        for l,r in Solution.hh:
            while num >= l:
                num -= l
                res += r
                # print(r)
            if num == 0:
                break
        return res