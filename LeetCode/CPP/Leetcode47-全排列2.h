#include <vector>
#include <algorithm>
using namespace std;
//全排列需要考虑重复的时候一般先对数组排序
//之后进行去重处理   
class Solution{
//因为有重复的情况需要考虑，所以先对数组进行排序
//之后对cur每个空缺位置填空
//如果之前这个数被使用过，就放弃这次（一般是顺序填充的时候）
public:
    vector<vector<int>> permuteUnique(vector<int> &nums){
        vector<vector<int>> result;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        visited.resize(nums.size());
        backTrack(result,cur,0,nums);
        return result;
    }
private:
    vector<int> visited;
    void backTrack(vector<vector<int>> &result,vector<int> &cur,int index,vector<int> &nums){
        if(index == nums.size()){
            result.push_back(cur);
        }
        int n = nums.size();
        for(int i =0;i<n;i++){
            //排序之后的数组，重复数之前访问过了，本次就不需要考虑这个组合
            //注意i>0的条件
            if(visited[i]||(i>0 && nums[i] == nums[i-1]&&visited[i-1])){
                continue;
            }
            visited[i] = 1;
            cur.push_back(nums[i]);
            backTrack(result,cur,index+1,nums);
            //回溯,撤销状态
            visited[i] = 0;
            cur.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums,used);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int> &nums,vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0;i < nums.size();++i){
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            if(i > 0 && nums[i - 1] == nums[i] && used[i-1] == false){
                continue;
            }
            //在树枝上，如果这个数字没用过
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums,used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};