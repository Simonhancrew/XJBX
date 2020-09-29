#include "ADT.hpp"
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }        
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

#include <queue>
//层序遍历的思想，层数刚好是树深
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if(root) {
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0;i < size;i++){
                auto tmp = que.front();
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
        }
        return depth;
    }
};