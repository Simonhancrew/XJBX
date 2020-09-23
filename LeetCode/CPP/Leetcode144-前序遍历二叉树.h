#include "ADT.hpp"
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root,res);
        return res;
    }
private:
    void DFS(TreeNode *root,vector<int> &res){
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);
        DFS(root->left,res);
        DFS(root->right,res);
    }
};

//迭代
#include <stack>
class Solution2{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto tmp = stk.top();
            stk.pop();
            if(tmp != nullptr) res.push_back(tmp->val);
            //记得当前节点为nullptr的话取消继续push
            else continue;
            stk.push(tmp->right);
            stk.push(tmp->left);
        }
        return res;
    }
};