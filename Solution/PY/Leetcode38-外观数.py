class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        pre = self.countAndSay(n - 1)
        length = len(pre)
        count = 1
        res = ""
        for i in range(length):
            if(i < length - 1 and pre[i] == pre[i + 1]):
                count += 1
            else:
                res += str(count) + pre[i]
                count = 1
        return res