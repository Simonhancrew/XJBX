//
// Created by han on 2020/8/27.
//
/* 
    之前一道华为的题目，1379-----三角矩阵，从顶点开始往下走，只能往下方相邻得位置走，左下，右下或者正下方。返回最大得路径和
    可以用动态规划
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxresult(vector<vector<int>> nums) {
        int layer = nums.size();
        vector<int> result;
        int cur = nums[0][0];
        DFS(nums, 1, result, cur, 0);
        sort(result.begin(), result.end());
        return result.back();
    }
private:
    void DFS(vector<vector<int>> nums, int layer, vector<int>& result, int cur, int index) {
        if (layer > nums.size() - 1) {
            result.push_back(cur);
            return;
        }
        //index是之前一层的下标
        int mid = index + 1;
        cur += nums[layer][mid];
        DFS(nums, layer + 1, result, cur, mid);
        cur -= nums[layer][mid];
        cur += nums[layer][(mid + 1 >= nums[layer].size()) ? mid : mid + 1];
        DFS(nums, layer + 1, result, cur, (mid + 1 >= nums[layer].size()) ? mid : mid + 1);
        cur -= nums[layer][(mid + 1 >= nums[layer].size()) ? mid : mid + 1];
        cur += nums[layer][((mid - 1) < 0) ? mid : mid - 1];
        DFS(nums, layer + 1, result, cur, ((mid - 1) < 0) ? mid : mid - 1);
    }
};
int main() {
    Solution solve;
    vector<vector<int>> a = { {0},{1,2,3},{1,2,3,4,5},{1,23,56,5,77,8,9},{199999,9,1,1,1,1,9,1,1111},{1,1,1,1,1,59999999,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,999999999} };
    auto results = solve.maxresult(a);
    cout << results<<'\n';
    system("pause");
    return 0;
}