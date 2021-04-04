from collections import defaultdict

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        if not answers:
            return 0
        dic = defaultdict(int)
        dic[answers[0]] = 1
        res = answers[0] + 1
        for i in range(1,len(answers)):
            if not dic[answers[i]]:
                dic[answers[i]] = 1
                res += answers[i] + 1
            else:
                if answers[i] == 0:
                    res += answers[i] + 1
                elif answers[i] + 1 > dic[answers[i]]:
                    dic[answers[i]] += 1
                else:
                    dic[answers[i]] = 1
                    res += answers[i] + 1
        return res