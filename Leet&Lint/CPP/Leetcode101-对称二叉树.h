#include "ADT.hpp"
//不要想成单课树遍历，对称问题想两个树的遍历就比较好想
class Solution {
    //其实是比较两颗树，往两个方向走，这种对称问题已经不是一棵树简单的前中后了
public:
    bool check(TreeNode *lhs, TreeNode *rhs) {
        if (!lhs && !rhs) return true;//都为空
        if (!lhs || !rhs) return false;//在不都为空的前提下，有一个不为空
        return lhs->val == rhs->val && check(lhs->left, rhs->right) && check(lhs->right, rhs->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

//也可以用迭代的方法来做
//只要对称的push节点就行
#include <queue>
using namespace std;
class Solution2 {
public:
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> que;
        //特殊情况判断
        if(root == nullptr) return true;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            auto lhs = que.front();
            que.pop();
            auto rhs = que.front();
            que.pop();
            //都是空节点，true
            if(lhs == nullptr && rhs == nullptr){
                continue;
            }
            //一节点空，另一不空，或者两val不等
            //!!!先判断null，否则会遇到null->left的问题
            if((lhs == nullptr||rhs == nullptr) ||lhs->val != rhs->val ){
                return false;
            }
            //对称的push入树的节点
            que.push(lhs->left);
            que.push(rhs->right);
            que.push(lhs->right);
            que.push(rhs->left);
        }
        return true;
    }
};