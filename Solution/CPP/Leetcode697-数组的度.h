#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(mp.count(nums[i])){
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }else{
                mp[nums[i]] = {1,i,i};
            }
        }
        int ans = 0;
        int maxnums = 0;
        for(auto& [_,vec]:mp){
            if(maxnums < vec[0]){
                maxnums = vec[0];
                ans = vec[2] - vec[1] + 1;
            }else if(maxnums == vec[0]){
                if(ans > vec[2] - vec[1] + 1){
                    ans = vec[2] - vec[1] + 1;
                }
            }
        }
        return ans;
    }
};