#include "ADT.hpp"
//最简单的递归
//用系统栈调用
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
#include <stack>
class Solution {
public:
    int countNodes(TreeNode* root){
        stack<TreeNode*> stk;
        int res = 0;
        if(root) stk.push(root);
        while(!stk.empty()){
            auto tmp = stk.top();
            stk.pop();
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
            res++;
        }
        return res;
    }
};
//看到节点的第一想法就是层序遍历。在一层的时候连续++节点
#include <queue>
using namespace std;
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        int node = 0;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i =0;i<size;i++){
                auto tmp = que.front();
                que.pop();
                node++;
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
        }
        return node;
    }
};