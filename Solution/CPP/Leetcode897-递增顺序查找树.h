#include "ADT.hpp" 
#include <vector>
using namespace std;
//利用了额外的空间构建一颗树
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return root;
        DFS(root);
        auto nroot = result[0];
        int n = result.size();
        for(int i = 0;i<n-1;++i){
            result[i]->left = nullptr;
            result[i]->right = result[i+1];
        }
        return nroot;
    }
private:
    vector<TreeNode*> result;
    void DFS(TreeNode* root){
        if(root == nullptr){
            return;
        }
        DFS(root -> left);
        auto nroot = new TreeNode(root->val); 
        result.push_back(nroot);
        DFS(root -> right);
    }
};
//中序遍历的迭代实现
//把左孩子先全部压入栈中，然后弹出，栈顶，找右孩子，root = rppt->right;
#include <stack>
vector<int> midorder(TreeNode* root){
    stack<TreeNode*> stk;
    vector<int> res;
    while(!stk.empty() || root!= nullptr){
        while(root != nullptr){
            stk.push(root);
            root = root->left;
        }
        if(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
            root = root->right;
        }
    }
    return res;
}

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        auto dummy = new TreeNode(-1);
        tail = dummy;
        dfs(root);
        return dummy->right;
    }
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        dfs(root->left);
        //防空当前root的左节点
        root->left = nullptr,tail->right = root;
        tail = root;
        dfs(root->right);
    }
    TreeNode* tail;
};