#include <vector>
#include <queue>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> Q;
        vector<int> view;
        if(root){
            Q.push(make_pair(root,0));
        }
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(view.size() == depth){
                view.push_back(node->val);
            }else{
                view[depth] = node->val;
            }
            if(node->left){
                Q.push(make_pair(node->left,depth+1));
            }
            if(node->right){
                Q.push(make_pair(node->right,depth+1));
            }
        }
        return view;
    }
};
//仿照层序遍历模板 leetcode-102
class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root){
        queue<TreeNode*> que;
        if(root!= nullptr) que.push(root);
        vector<int> vec;
        while(!que.empty()){
            int size = que.size();
            for(int i =0;i<size;i++){
                auto tmp = que.front();
                que.pop();
                //当i是层序的最右边一个值的时候入vector
                if(i == size-1){
                    vec.push_back(tmp->val);
                }
                //队列先进先出，设定size为一个固定值，pop出一层所有的节点
                if(tmp->left != nullptr) que.push(tmp->left);
                if(tmp->right != nullptr) que.push(tmp->right);
            }
        }
        return vec;
    }
};