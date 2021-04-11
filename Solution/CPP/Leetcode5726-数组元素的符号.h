#include <vector>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0,nag = 0;
        for(auto &num:nums){
            if(num == 0){
                return 0;
            }
            if(num > 0){
                pos ++;
            }else{
                nag++;
            }
        }
        if(nag % 2 == 0){
            return 1;
        }
        return -1;
    }
};