#include "ADT.hpp"
//就是在玩中序的有序性
//有陷进，不能只比较左右节点和中节点
//可能后序子树中存在不符合情况的值
//1 中序一定有序，利用额外空间
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        Traverse(root);
        int n = vec.size();
        for(int i = 1;i<n;++i){
            if(vec[i]<=vec[i-1]){
                return false;
            }
        }
        return true;
    }
private:
    vector<int> vec;
    void Traverse(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Traverse(root->left);
        vec.push_back(root->val);
        Traverse(root->right);
    }
};

//2 递归的判断整颗树
class Solution {
public:
    //需要全局记录这个pre
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        bool left = isValidBST(root->left);
        if(pre!=nullptr&&pre->val>root->val){
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left&right;
    }
};

//3 迭代的判断
#include <stack>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while(cur!=nullptr||!stk.empty()){
            if(cur!=nullptr){
                stk.push(cur);
                cur = cur->left;
            }else{
                auto tmp = stk.top();
                stk.pop();
                if(pre!=nullptr&&pre->val>=tmp->val){
                    return false;
                }
                pre = tmp;
                cur = tmp->right;
            }
        }
        return true;
    }
};