#include <vector>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2;
        getnode(root1,res1);
        getnode(root2,res2);
        if(res1.size() != res2.size()) return false;
        for(int i = 0;i < res1.size();i++){
            if(res1[i] != res2[i]) return false;
        }
        return true;
    }
    void getnode(TreeNode* root,vector<int> &res){
        if(!root){
            return;
        }
        if(!root->left && !root->right) res.push_back(root->val);
        getnode(root->left,res);
        getnode(root->right,res);
    }
};