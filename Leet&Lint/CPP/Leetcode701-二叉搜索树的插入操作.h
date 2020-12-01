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
    //终止条件就是找到遍历的节点为null的时候，就是要插入节点的位置了，并把插入的节点返回。
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        //搜索树是有方向了，可以根据插入元素的数值，决定递归方向。
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);

        //上一层将加入节点返回，本层用root->left或者root->right将其接住
        return root;
    }
};