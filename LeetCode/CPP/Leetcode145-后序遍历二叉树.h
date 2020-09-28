#include "ADT.hpp"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//后序是左右中，较前序调整一下入栈顺序之后reverse
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            auto tmp = stk.top();
            stk.pop();
            //遇子叶节点，本次循环结束
            if(tmp!= nullptr) res.push_back(tmp->val);
            else continue;
            stk.push(tmp->left);
            stk.push(tmp->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//递归的代码
class Solution2 {
public:
    void DFS(TreeNode* root,vector<int> &res){
        if(root == nullptr) return;
        DFS(root->left,res);
        DFS(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        DFS(root,res);
        return res;
    }
};