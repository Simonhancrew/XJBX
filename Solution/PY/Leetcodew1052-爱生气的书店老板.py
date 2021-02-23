from typing import List
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        init = 0
        for i,val in enumerate(customers):
            if grumpy[i] == 0:
                init += val
        increase = 0
        for i in range(X):
            increase += grumpy[i] * customers[i]

        maxincrease = increase
        n = len(customers)
        for i in range(X,n):
            increase += customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X]
            maxincrease = max(increase,maxincrease)
        
        return init + maxincrease 
        