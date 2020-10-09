#include "ADT.hpp"
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //pre_indx不断的++，其实就是在模拟下一次的根节点的往前推进过程
    int pre_index;
    unordered_map<int,int> idx_map;
    //pre的第一个就是根节点，递归建树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_index = 0;
        //构建一个中序中的当前值到当前下标的pair
        int idx = 0;
        for(auto i:inorder){
            idx_map[i] = idx++;
        }
        return buildTreeNode(0,(int)inorder.size()-1,preorder,inorder);
    }
private:
    TreeNode* buildTreeNode(int lhs,int rhs,vector<int>& preorder, vector<int>& inorder){
        if(lhs>rhs){
            return nullptr;
        }
        int root_val = preorder[pre_index];
        TreeNode* root = new TreeNode(root_val);
        //拿到中序中的位置
        int root_idx = idx_map[root_val];
        //下一次的根节点 
        pre_index++;
        root->left = buildTreeNode(lhs,root_idx-1,preorder,inorder);
        root->right = buildTreeNode(root_idx+1,rhs,preorder,inorder);
        return root;
    }
};


//leetcode的解法
class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
//迭代的解法
#include<stack>
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};