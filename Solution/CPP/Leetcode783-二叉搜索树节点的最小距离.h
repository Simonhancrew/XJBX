#include "ADT.hpp"
#include <climits>
#include <stdlib.h>
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX,pre = -1;
        DFS(root,pre,ans);
        return ans;
    }
private:
    void DFS(TreeNode* root,int& pre,int& ans){
        if(root == nullptr){
            return;
        }
        DFS(root->left,pre,ans);
        if(pre == -1){
            pre = root->val;
        }else{
            ans = min(ans,abs(root->val-pre));
            pre = root->val;
        }
        DFS(root->right,pre,ans);
    }
};