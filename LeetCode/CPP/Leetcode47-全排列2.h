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