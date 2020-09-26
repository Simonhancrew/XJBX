#include <vector>
#include "ADT.hpp"
using namespace std;
//深搜加回溯
//先序遍历加，后序遍历减，刚刚好形成回溯。
//对于路径问题找好每个搜索序要做什么
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        int path_value = 0;
        if(root) DFS(root,sum,path,result,path_value);
        return result;
    }
private:
    void DFS(TreeNode* root,int sum,vector<int> &path,vector<vector<int>> &result,int path_value){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        path_value += root->val;
        if(root->left == nullptr && root->right == nullptr && path_value == sum){
            result.push_back(path);
        }
        DFS(root->left,sum,path,result,path_value);
        DFS(root->right,sum,path,result,path_value);
        path.pop_back();
    }
};