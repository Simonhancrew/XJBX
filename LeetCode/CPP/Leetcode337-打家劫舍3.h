struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val +g[root->left]+g[root->right];
        g[root] = max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};