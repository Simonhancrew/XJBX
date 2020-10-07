#include "ADT.hpp"
#include <queue>
using namespace std;
//最简单的思路就是层序遍历，记录每行第一个数值
//结束的时候返回
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        int res;
        while(!que.empty()){
            int size = que.size();
            //层序遍历
            for(int i =0;i<size;i++){
                auto tmp = que.front();
                //记录每个一层的第一个节点，当最后一层结束时
                //该值就是左下的值
                if(i == 0) res = tmp->val;
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
        }
        return res;
    }
};

//递归的思路
//从上到下遍历，记录树的最大深度
//到达子叶节点之后，比较二者深度，深度更大的话更新mostright
class Solution {
public:
    int mostleft;
    int depth = INT_MIN;
    void DFS(TreeNode* root,int leftdepth){
        //遇到子叶节点，比较最大深度。深度更大的话更新节点的value
        if(root->left == nullptr && root->right == nullptr){
            if(leftdepth > depth){
                mostleft = root->val;
                depth = leftdepth;
            }
            return;
        }
        if(root->left){
            DFS(root->left,leftdepth+1);
        }
        if(root->right){
            DFS(root->right,leftdepth+1);
        }
        return;//可写可不写
    }
    int findBottomLeftValue(TreeNode* root) {
        DFS(root,0);
        return mostleft;
    }
};