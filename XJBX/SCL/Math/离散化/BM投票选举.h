//找到数组中的大多数
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = -1,count = 0;
        for(auto num:nums){
            if(count == 0) candi = num;
            if(candi == num) count++;
            else count--;
        }
        count = 0;
        for(auto num:nums){
            if(candi == num) count++;
        }
        return count * 2 > nums.size() ?candi:-1; 
    }
};