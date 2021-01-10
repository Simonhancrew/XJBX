#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        while(i < n){
            int start = i;
            i++;
            while(i < n && nums[i] == nums[i-1] + 1){
                i++;
            }
            int end = i - 1;
            string cur = to_string(nums[start]);
            if(start < end){
                cur.append("->");
                cur.append(to_string(nums[end]));
            }
            res.push_back(move(cur));
        }
        return res;
    }
};