#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(),col = nums[0].size();
        if(row * col != r * c){
            return nums;
        } 
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                int l = (i*c + j) / col;
                int r = (i*c + j) % col;
                ans[i][j] = nums[l][r];
            }
        }
        return ans;
    }
};