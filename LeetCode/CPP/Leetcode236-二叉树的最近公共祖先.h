#include "ADT.hpp"
#include <vector>
using namespace std;
//前序找到路径，遍历这个较短的路径，找到相同的最后一个node
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int finish = 0;
        vector<TreeNode*> path;
        vector<TreeNode*> node_p;
        vector<TreeNode*> node_q;
        preorder(root,p,path,node_p,finish);
        finish =0;
        path.clear();
        preorder(root,q,path,node_q,finish);
        int path_len = 0;
        if(node_q.size()>node_p.size()){
            path_len = node_p.size();
        }else{
            path_len = node_q.size();
        }
        TreeNode* result =0;
        for(int i=0;i<path_len;i++){
            if(node_q[i]==node_p[i]){
                result = node_p[i];
            }
        }
        return result;
    }

private:
    void preorder(TreeNode* node,TreeNode *search,vector<TreeNode*> &path,vector<TreeNode*> &result,int &finish){
        if(!node||finish ==1){
            return;
        }
        path.push_back(node);
        if(node == search){
            finish =1;
            result = path;
        }
        preorder(node->left,search,path,result,finish);
        preorder(node->right,search,path,result,finish);
        path.pop_back();

    }
};

//后序天然回溯
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //从子节点穿node回上层
        if (root == q || root == p || root == NULL) return root;
        //左子树和右子树传回来的值
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //都不空，则这个节点就是公共，往上传
        if (left != NULL && right != NULL) return root;
        //左空，从右侧传上来的，继续往上传
        if (left == NULL && right != NULL) return right;
        //右空，从左侧传上来的
        else if (left != NULL && right == NULL) return left;
        //都空，找不到这两个节点
        else  { //  (left == NULL && right == NULL)
            return NULL;
        }

    }
};