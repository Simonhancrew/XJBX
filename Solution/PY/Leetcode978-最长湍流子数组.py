from typing import List
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        ans = 1
        direction = True
        start ,end = 0,1
        while end < n:
            if end == start + 1:
                if arr[end - 1] > arr[end]:
                    direction = True
                    ans = max(ans,2)
                elif arr[end - 1] < arr[end]:
                    direction = False
                    ans = max(ans,2)
                else:
                    start += 1
                end += 1
            else:
                if (arr[end - 1] > arr[end] and not direction) or (arr[end - 1] < arr[end] and direction):
                    ans = max(ans,end - start + 1)
                    end+=1
                    direction = not direction
                else:
                    start = end -1
        
        return ans