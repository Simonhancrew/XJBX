#include "ADT.hpp"
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int res = 0;
        if(root->left !=nullptr && (root->left->left == nullptr && root->left->right == nullptr)){
            res +=root->left->val;
        }else{
            res += sumOfLeftLeaves(root->left);
        }
        res+=sumOfLeftLeaves(root->right);
        return res;
    }
};
//bfs
#include <queue>
using namespace std;
class Solution2 {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue q{deque{root}};
        int ans = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    ans += node->left->val;
                }
                else {
                    q.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

//改迭代后序
#include <stack>
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        int result = 0;
        while(!stk.empty()){
            auto tmp = stk.top();
            stk.pop();
            if(tmp->left != nullptr && tmp->left->left == nullptr && tmp->left->right == nullptr){
                result += tmp->left->val;
            }
            if(tmp->left) stk.push(tmp->left);
            if(tmp->right) stk.push(tmp->right);
        }
        return result;
    }
};