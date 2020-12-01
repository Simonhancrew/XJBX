#include "ADT.hpp"
//中序逆反，sum累加
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        DFS(root);
        return root;
    }
private:
    int  sum = 0;
    void DFS(TreeNode* root){
        if (root == nullptr){
            return;
        }
        DFS(root->right);
        sum += root->val;
        root->val = sum;
        DFS(root->left);
    }
};