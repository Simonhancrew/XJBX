class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l,r = 1,n
        while l < r:
            mid = l + r >> 1
            if not isBadVersion(mid):
                l = mid + 1
            else:
                r = mid
        return l