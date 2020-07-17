//找到第一个大于等于target的数的位置就可以了
//注意while(lo<=hi)才是完全搜索全部的空间，因为我设置的hi == nums.size()-1;
#include<vector>
using namespace std;
class Solution{
public:
    int searchInsert(vector<int> &nums,int target){
        int lo = 0,hi = nums.size()-1;
        int pos = nums.size();
        while(lo<=hi){
            int mid =((hi-lo)>>1)+lo;
            if(target<=nums[mid]){
                pos = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return pos;
    }
};