#include "ADT.hpp"
#include <stack>
//选用先序，交换节点的左右孩子
//递归
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return root;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }  
};
//迭代
class Solution2 {
public:
    TreeNode* invertTree(TreeNode *root){
        std::stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur == nullptr){
                continue;
            }
            auto tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;

            st.push(cur->left);
            st.push(cur->right);
        }
        return root;
    }
};