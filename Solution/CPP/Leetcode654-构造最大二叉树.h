#include "ADT.hpp"
//递归建树，蠢的一批
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Traverse(nums,0,nums.size()-1);
    }
private:
    TreeNode* Traverse(vector<int> &nums,int lhs,int rhs){
        //递归终止条件
        //传进去的数组不是大小为1
        //经典判断就是lhs>rhs
        if  (lhs>rhs) {
            return NULL;
        }
        //记录max的index，方便就地操作数组
        int maxindex = lhs;
        //拿到数组范围的max值
        for(int i = lhs;i<=rhs;i++){
            if(nums[i] > nums[maxindex]){
                maxindex = i;
            }
        }
        TreeNode *root = new TreeNode(nums[maxindex]);
        root->left = Traverse(nums,lhs,maxindex-1);
        root->right = Traverse(nums,maxindex+1,rhs);
        return root;
    }
};