#include "ADT.hpp"
#include <vector>
using namespace std;
//公共节点的问题，深搜加回溯找到路径，然后选取短路径，从后向前找相同的
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        vector<TreeNode*> cur;
        bool finish = false;
        DFS(path_p,cur,finish,root,p);
        //清空cache
        cur.clear();
        finish = false;
        DFS(path_q,cur,finish,root,q);
        //从短路径开始，因为前部份的路径是公共的。只要从短路径中找到第一个相等的节点
        int minlen = path_p.size()>path_q.size()?path_q.size():path_p.size();
        for(int i = minlen-1;i>=0;--i){
            if(path_p[i] == path_q[i]){
                return path_p[i];
            }
        }
        //连根节点都不相同的话就说明p和q至少有一个不在树中，没有公共的节点
        return nullptr;
    }
private:
    //先序遍历+回溯，记录找到节点的相关路径
    void DFS(vector<TreeNode*> &result,vector<TreeNode*> &cur,bool finish,TreeNode* root,TreeNode* search){
        if(root == nullptr || finish == true){
            return;
        }
        cur.push_back(root);
        if(root == search){
            result = cur;
            finish = 1;
        }
        DFS(result,cur,finish,root->left,search);
        DFS(result,cur,finish,root->right,search);
        cur.pop_back();//回溯
    } 
};

//利用bst的性质，一次遍历
//三种情况
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            //pq的值小于当前节点，往左
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            //大于当前的节点，往右找
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            //到达分叉点，结束
            else {
                break;
            }
        }
        return ancestor;
    }
};