#include "ADT.hpp"
#include <vector>
using namespace std;
//递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode *root,vector<int> &res){
        if(root == nullptr){
            return;
        }
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
};

//栈调用

class Solution2 {
public:    
    vector<int> inorderTraversal(TreeNode* root){

    }
};

//morris遍历

class Solution {
public:    
    vector<int> inorderTraversal(TreeNode* root){
        
    }
};