#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto num:nums){
            hash[num] ++;
        }
        int ans = 0;
        for(auto h:hash){
            if(h.second == 1){
                ans = h.first;
                break;
            }
        }
        return ans;
    }
};

#include <vector>
//考虑数组中出现一次元素的做法，考虑该数二进制的每一位，如果所有的数中出现1的次数是 3 * K + 1的话就是1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++) {
            int counter = 0;
            for (int i = 0; i < nums.size(); i++)
                counter += (nums[i] >> bit) & 1;
            ans += (counter % 3) << bit;
        }

        return ans;
    }
};