/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//对于每个节点，递归的找（start,i-1）和(i+1,end)的子树，然后将他们连接起来
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       if(!n){
           return {};
       }
       return generateTrees(1,n);
        
    }
private:
    vector<TreeNode*> generateTrees(int start,int end){
        if(start>end){
            return {nullptr};
        }
        vector<TreeNode*> alltree;
        for(auto i = start;i<=end;i++){
            vector<TreeNode*> leftTreenode = generateTrees(start,i-1);
            vector<TreeNode*> rightTreenode = generateTrees(i+1,end);
            for (auto left:leftTreenode){
                for(auto right:rightTreenode){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    alltree.push_back(cur);
                    delete cur;
                }
            }
        }
        return alltree;
    }
};