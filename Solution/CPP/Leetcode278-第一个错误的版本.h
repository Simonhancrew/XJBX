class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,r = n;
        while(l < r){
            int mid = (long long)l + r >> 1;
            if(!isBadVersion(mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};