#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    vector<TreeNode*> vec;
    void DFS(TreeNode* root){
        if(root == nullptr){
            return;
        }
        vec.push_back(root);
        DFS(root->left);
        DFS(root->right);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        DFS(root);
        for(int i = 0;i<vec.size()-1;i++){
            vec[i]->right = vec[i+1];
            vec[i]->left = nullptr;
        }
        vec[vec.size()-1]->right = nullptr;
        vec[vec.size()-1]->left = nullptr;
    }
};

//更优雅的做法，类morris遍历。就地生成，不使用额外空间
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};