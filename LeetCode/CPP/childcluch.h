#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item);
        generate(0, nums, item, result);
        return  result;

    }
private:
    void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }
};

class Solution2 {

 /*
 {A,B,C}为集合，A为100 = 4，B为010 = 2，c为001 = 1
 构造集合，使用A，B，C对应的三个整数与该集合对应的整数做& 运算，当为真时，将该元素push进入集合。
  */

    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int all = 1 << nums.size();
        for (int i = 0; i < all; i++) {
            vector<int> item;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return  result;

    }
};
