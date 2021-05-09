#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size();
        for(int i = 0;i < n;++i){
            if(i > nums2.size()) break;
            int l = i,r = nums2.size() - 1;
            while(l < r){
                int mid =  l + r + 1>> 1;
                if(nums2[mid] >= nums1[i]) l = mid;
                else r = mid - 1;
            }
            res = max(res,l - i);
        }
        return res;
    }
};