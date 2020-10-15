#include "ADT.hpp" 
#include <climits>
#include <algorithm>
#include <stdlib.h>
using namespace std;
//树至少有两个节点,因为是搜索二叉树，所以最小值一定来自中序的相邻值
//中序遍历，求相邻值之差，返回最小的
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        DFS(root, pre, ans);
        return ans;
    }
private:
    //传引用，全局修改
    void DFS(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) {
            return;
        }
        DFS(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        DFS(root->right, pre, ans);
    }
};

//迭代的方法
#include <stack>
using std::stack;
class Solution {
public:
    int getMinimumDifference(TreeNode* root){
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int res = INT_MAX;
        while(cur!=nullptr||!stk.empty()){
            if(cur!=nullptr){
                stk.push(cur);
                cur = cur->left;
            }else{
                cur = stk.top();
                stk.pop();
                if(pre != nullptr){
                    res = min(res,cur->val-pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};