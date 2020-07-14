#pragma once
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        vector<TreeNode*> node_vec;
        preorder_insert(nums, node_vec, 0, nums.size() - 1);
        for (int i = 1; i < node_vec.size(); i++) {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
private:
    void preorder_insert(vector<int>& nums, vector<TreeNode*>& node_vec, int begin, int end) {
        if (begin > end) {
            return;
        }
        int mid = (begin + end) >> 1;
        node_vec.push_back(new TreeNode(nums[mid]));
        preorder_insert(nums, node_vec, begin, mid - 1);//mid-1
        preorder_insert(nums, node_vec, mid + 1, end);
    }
    void BST_insert(TreeNode* node, TreeNode* insert_node) {
        if (insert_node->val < node->val) {
            if (node->left) {
                BST_insert(node->left, insert_node);
            }
            else {
                node->left = insert_node;
            }
        }
        else {
            if (node->right) {
                BST_insert(node->right, insert_node);
            }
            else {
                node->right = insert_node;
            }
        }
    }
};