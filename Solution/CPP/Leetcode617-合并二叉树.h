#include "ADT.hpp"
#include <queue>
#include <algorithm>
using namespace std;
//创建新树，不要原地修改一颗树
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //空的情况的处理，继承半边或返回nullptr
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        //递归的处理另外的子树
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};

//广度优先
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        auto q = queue<TreeNode*>();
        auto queue1 = queue<TreeNode*>();
        auto queue2 = queue<TreeNode*>();
        q.push(merged);
        queue1.push(t1);
        queue2.push(t2);
        while (!queue1.empty() && !queue2.empty()) {
            auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
            q.pop();
            queue1.pop();
            queue2.pop();
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            //左节点至少有一个不为空
            if (left1 != nullptr || left2 != nullptr) {
                //都不为空
                if (left1 != nullptr && left2 != nullptr) {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    queue1.push(left1);
                    queue2.push(left2);
                }//有一个为空，就不用继续下去，直接继承不空的半边树 
                else if (left1 != nullptr) {
                    node->left = left1;
                } else if (left2 != nullptr) {
                    node->left = left2;
                }
            }
            //右节点至少一个不为空
            if (right1 != nullptr || right2 != nullptr) {
                //都不为空
                if (right1 != nullptr && right2 != nullptr) {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    queue1.push(right1);
                    queue2.push(right2);
                } 
                //有一个为空，同样继承另一半
                else if (right1 != nullptr) {
                    node->right = right1;
                } else {
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};