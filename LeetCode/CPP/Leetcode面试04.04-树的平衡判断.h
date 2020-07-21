#include<stdlib.h>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x), left(left), right(right){}
    TreeNode(int x){
        val = x;
        left = nullptr;
        right =nullptr;
    }

};
class Solution {
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution2{
public:
    bool isBalanced(TreeNode* root){
        if(root == nullptr) return true;
        dfs(root);
        return flag;
    }
private:
    bool flag = true;
    int dfs(TreeNode* root){
        if(root == nullptr|| !flag){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(left-right)>1){
            flag = false;
        }
        return max(left+1,right+1);
    }
};