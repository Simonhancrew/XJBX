#include <vector>

using namespace std;

//每必要去二分，复杂度最坏也是n
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto &num:nums){
            if(num == target){
                return true;
            }
        }
        return false;
    }
};