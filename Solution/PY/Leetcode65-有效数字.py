class Solution:
    def ispurenumber(self,s,must_be_int):
        if not s:
            return False
        has_dot,has_digit = False,False

        st = 1 if s[0] == '+' or s[0] == '-' else 0

        for i in range(st,len(s)):
            if s[i] == '.':
                if must_be_int:
                    return False
                if has_dot:
                    return False
                has_dot = True
            elif s[i].isdigit():
                has_digit = True
            else:
                return False
        
        return has_digit
    
    def isNumber(self, s: str) -> bool:
        eps = s.find('e')
        Eps = s.find('E')

        if (eps != -1):
            return self.ispurenumber(s[:eps],False) and self.ispurenumber(s[eps+1:],True)

        if (Eps != -1):
            return self.ispurenumber(s[:Eps],False) and self.ispurenumber(s[Eps+ 1:],True)
    
        return self.ispurenumber(s,False)
