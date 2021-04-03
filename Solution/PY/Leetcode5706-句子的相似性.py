#往两边剔，前后一定要有一个能匹配
class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        if len(s1) > len(s2):
            s1,s2 = s2,s1
        a1 = s1.split()
        a2 = s2.split()
        while a1:
            if a1[0] != a2[0] and a1[-1] != a2[-1]:
                return False
            if a1[0] == a2[0]:
                a1.pop(0)
                a2.pop(0)
            if a1 and a1[-1] == a2[-1]:
                a1.pop()
                a2.pop()
        return True