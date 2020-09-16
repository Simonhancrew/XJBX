#include "ADT.hpp"
#include <stack>
//递归
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if(root == nullptr){
            return root;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
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