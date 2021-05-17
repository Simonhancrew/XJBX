#include <queue>
#include "ADT.hpp"
class Solution {
public:
    int x,y,xd,yd;
    bool fdx = false,fdy = false;
    TreeNode *xp,*yp; 
    void check(TreeNode* node,TreeNode* parent,int deep){
        if(node->val == x){
            xd = deep,xp = parent,fdx = true;
        }else if(node->val == y){
            yd = deep,yp = parent,fdy = true;
        }
    }
    bool isCousins(TreeNode* root, int _x, int _y) {
        x = _x,y = _y;
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        check(root,nullptr,0);
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            if(tmp.first->left){
                que.push({tmp.first->left,tmp.second + 1});
                check(tmp.first->left,tmp.first,tmp.second + 1);
            }
            if(tmp.first->right){
                que.push({tmp.first->right,tmp.second + 1});
                check(tmp.first->right,tmp.first,tmp.second + 1);
            }
            if(fdx && fdy){
                break;
            }
        }
        return yd == xd && xp != yp;
    }
};