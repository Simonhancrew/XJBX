class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        patternsize = len(s1)
        n = len(s2)
        if patternsize > n:
            return False
        nums1 = [0] * 26
        nums2 = [0] * 26
        for i in range(patternsize):
            nums1[ord(s1[i]) - ord('a')] += 1
            nums2[ord(s2[i]) - ord('a')] += 1
        if nums1 == nums2 :
            return True
        for i in range(patternsize,n):
            nums2[ord(s2[i]) - ord('a')] += 1 
            nums2[ord(s2[i - patternsize]) - ord('a')] -= 1
            if nums1 == nums2:
                return True
        return False