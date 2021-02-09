from typing import List
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int: 
        n = len(A)
        start1,total1 = 0,0
        start2,total2 = 0,0
        ans = 0
        end = 0
        nums1 = [0] * (n+1)
        nums2 = [0] * (n+1)
        while end < n:
            if nums1[A[end]] == 0:
                total1 += 1
            nums1[A[end]] += 1
            if nums2[A[end]] == 0:
                total2 += 1
            nums2[A[end]] += 1
            while total1 > K:
                nums1[A[start1]] -= 1
                if nums1[A[start1]] == 0:
                    total1 -= 1
                start1 += 1
            while total2 > K-1:
                nums2[A[start2]] -= 1
                if nums2[A[start2]] == 0:
                    total2 -= 1
                start2 += 1
            ans += start2 - start1
            end += 1
        return ans