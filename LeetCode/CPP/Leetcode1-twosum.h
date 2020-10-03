#include <vector>
#include <unordered_map>
using namespace std;
//暴力枚举，最坏情况下时间复杂度O（n**2）
//利用哈希，空间换时间.
//设置数值->下标映射
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int n = nums.size();
        for(int i =0;i < n;i++){
            if(umap.find(target-nums[i]) != umap.end()){
                return {umap[target-nums[i]],i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
