#include "ADT.hpp"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> listNode;
        if(root == nullptr){
            return result;
        }
        listNode.push(root);
        while(!listNode.empty()){
            int n = listNode.size();
            vector<int> cur;
            //输出当前全部节点的技巧
            for(int i = 0;i<n;i++){
                auto node = listNode.front();
                listNode.pop();
                cur.push_back(node->val);
                if(node->left){
                    listNode.push(node->left);
                }
                if(node->right){
                    listNode.push(node->right);
                }
            }
            result.push_back(cur);
        }
        reverse(result.begin(),result.end());
        return result;    
    }
};