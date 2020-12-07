#include "ADT.hpp"
//非常简单的递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr || root->val == val){
            return root;
        }
        if(root->val>val) return searchBST(root->left,val);
        if(root->val<val) return searchBST(root->right,val);
        return nullptr;
    }
};

//迭代的方式
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val>val) root = root->left;
            else if (root->val <val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};