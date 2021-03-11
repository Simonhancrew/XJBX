class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)
        presign = '+'
        st = []
        num = 0

        def isNumber(char):
            if char >= '0' and char <= '9':
                return True
            return False

        for i in range(n):
            if isNumber(s[i]):
                num = num * 10 + ord(s[i]) - ord('0')
            if not isNumber(s[i]) and s[i] != ' ' or i == n - 1:
                if presign == '+':
                    st.append(num)
                elif presign == '-':
                    st.append(-num)
                elif presign == '*':
                    st[-1] = st[-1] * num
                else:
                    #注意地板除的问题是向下取整的
                    if st[-1] < 0:
                        st[-1] = int(st[-1]/num)
                    else:
                        st[-1] //= num
                presign = s[i]
                num = 0
        return sum(st)
