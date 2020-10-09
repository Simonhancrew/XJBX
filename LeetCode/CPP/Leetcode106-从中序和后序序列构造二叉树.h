#include <vector>
#include <unordered_map>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    int post_index;
    unordered_map<int,int> idx_map; 
    TreeNode* buildTree(vector<int> &inorder,vector<int> postorder) {
        post_index = postorder.size()-1;//拿到根节点的位置
        //构建一个中序的下标和位置对
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return buildTreeNode(0,(int)inorder.size()-1,inorder,postorder);
    }
private:
    TreeNode* buildTreeNode(int lhs,int rhs,vector<int> inorder,vector<int> postorder){
        //数组为空的话就结束了
        //递归终止条件
        if(lhs>rhs){
            return nullptr;
        }
        //从后序中拿到当前根节点
        int rootVal = postorder[post_index];
        TreeNode* root = new TreeNode(rootVal);
        //下一次的根节点idx
        post_index--;
        //拿到中序中的区分点
        int index = idx_map[rootVal];
        //注意构建的顺序,因为postindex是按照后序的，所以先构建的是右子树
        root->right = buildTreeNode(index+1,rhs,inorder,postorder);
        root->left = buildTreeNode(lhs,index-1,inorder,postorder);
        return root;
    }
};

//迭代的方法
#include <stack>
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        auto s = stack<TreeNode*>();
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; i--) {
            int postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIndex]) {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            } else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
};