from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        tmp = []
        i,j = 0,0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                tmp.append(nums1[i])
                i += 1
            else:
                tmp.append(nums2[j])
                j += 1
        while i < m:
            tmp.append(nums1[i])
            i += 1
        while j < n:
            tmp.append(nums2[j])
            j += 1
        for i in range(len(nums1)):
            nums1[i] = tmp[i]


###原地，逆着开始
class Solution2:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i,j,k = m-1,n-1,m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] <= nums2[j]:
                nums1[k] = nums2[j]
                j -= 1
            else:
                nums1[k] = nums1[i]
                i -= 1
            k -= 1
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1