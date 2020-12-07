#include "ADT.hpp"
class Solution {
public:
    vector<int> memo;
    int sumNumbers(TreeNode* root){
        int cur = 0;
        int res = 0;
        DFS(root,0);
        for(auto num:memo){
            res += num;
        }
        return res;
    }
private:    
    void DFS(TreeNode* root,int cur){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            cur = 10*cur + root->val;
            memo.push_back(cur);
            return;
        }
        cur = 10*cur + root->val;
        DFS(root->left,cur);
        DFS(root->right,cur);
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};