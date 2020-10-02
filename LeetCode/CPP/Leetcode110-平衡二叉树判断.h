#include<cmath>
#include<algorithm>
#include "ADT.hpp"
using namespace std;
//递归的方法是最简单的，首先思考树平衡的条件，左右树的高度差不能超过1，这就需要一个判断树高的函数。
//然后我们递归的判断左子树和右子树的高度。最后就可以得到当前节点的最大高度。基准条件，到达空节点，返回高度0
//之后的Solution主函数，判断节点左树和右树的高度差是否大于1，是的话直接返回false;否则，继续递归判断左儿子和右儿子。
//最后需要考虑一些边界条件，树空时，直接返回true
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(maxdepth(root->left)-maxdepth(root->right))>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
private:
    int maxdepth(TreeNode *Node){
        if(Node == NULL) return 0;
        return max(maxdepth(Node->left),maxdepth(Node->right))+1;
    }
};

//另外一种写法
class Solution {
public:
    // 返回以该节点为根节点的二叉树的高度，如果不是二叉搜索树了则返回-1
    int getDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        if (leftDepth == -1) return -1; // 说明左子树已经不是二叉平衡树
        int rightDepth = getDepth(node->right);
        if (rightDepth == -1) return -1; // 说明右子树已经不是二叉平衡树
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true; 
    }
};

//改迭代
#include <stack>
class Solution {
private:
    //专门处理高度问题的函数
    int getDepth(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

public:
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return true;
    }
};