#include <queue>
#include <vector>
#include <algorithm>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        vector<int> cur;
        int direction = 0;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            cur.clear();
            for(int i = 0;i < size;i++){
                auto tmp = que.front();
                cur.push_back(tmp->val);
                que.pop();
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
            if(direction % 2 == 1){
                reverse(cur.begin(),cur.end());
            }
            ans.push_back(cur);
            ++direction;               
        }
        return ans;
    }
};