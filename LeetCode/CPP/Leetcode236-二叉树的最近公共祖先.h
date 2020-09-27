#include "ADT.hpp"
#include <vector>
using namespace std;
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