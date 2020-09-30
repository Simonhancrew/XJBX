#include "ADT.hpp"
//不用考虑DFS,直接模拟向下就可以了
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }
        auto tmp = root;
        while(tmp != nullptr){
            if(val<tmp->val){
                if(tmp->left == nullptr){
                    tmp->left = new TreeNode(val);
                    break;
                }
                tmp = tmp->left;
            }else{
                if(tmp->right == nullptr){
                    tmp->right = new TreeNode(val);
                    break;
                }
                tmp = tmp->right;
            }
        }
        return root;
    }
};
//递归的解法
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};