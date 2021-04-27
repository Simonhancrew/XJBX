#include "ADT.hpp";
class Solution {
public:
    int res;
    int low,high;
    int rangeSumBST(TreeNode* root, int low, int high) {
        res = 0;
        this->low = low,this->high = high;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(root->val >= low && root->val <= high) res += root->val;
        dfs(root->right);
    }
};