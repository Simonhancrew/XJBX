#include "ADT.hpp"
#include <string>

using namespace std;

class Codec {
public:

    string path;
    string serialize(TreeNode* root) {
        dfs_s(root);
        return path;
    }
    void dfs_s(TreeNode* root){
        if(root == NULL){
            path += "#,";
            return;
        }
        path += to_string(root->val) + ',';
        dfs_s(root->left);
        dfs_s(root->right);
    }

    TreeNode* deserialize(string data) {
        int u = 0;
        auto res = dfs_d(data,u);
        return res;
    }

    TreeNode* dfs_d(string& data,int& u){
        if(data[u] == '#'){
            u += 2;
            return NULL;
        }
        int k = u;
        while(data[u] != ',') u++;
        auto node = new TreeNode(stoi(data.substr(k,u - k)));
        u++;//跳过逗号
        node->left = dfs_d(data,u);
        node->right = dfs_d(data,u);
        return node;
    }
};