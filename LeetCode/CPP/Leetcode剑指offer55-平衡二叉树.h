using NULL = std::nullptr_t;
#include<cmath>
#include<algorithm>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(left-right)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);//记得找所有的不平衡可能
    }
private: 
    int dfs(TreeNode* root){
        int height;
        if(root == NULL){
            height = 0;
            return height;
        }
        height = 1 + max(dfs(root->left),dfs(root->right));
        return height;
    }
};