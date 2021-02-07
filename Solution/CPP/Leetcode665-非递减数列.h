#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0;i < n - 1;i++){
            int x = nums[i],y = nums[i+1];
            //这里肯定是要改一个数的
            if (x > y){
                cnt++;
                if(cnt > 1){
                    return false;
                }
                //如果nums[i+1] > nums[i-1]直接把nums[i]变成nums[i+1]就可以了
                //此时到nums[i+1]都是有序的，不做这个变的操作，让cnt+1对之后不会有影响
                if(i > 0 && y < nums[i-1]){
                    //此时只能让i+1的位置变为nums[i],这让才能让i+1的位置符合要求
                    nums[i+1] = nums[i]; 
                }
            }
        }
        return true;
    }
};
