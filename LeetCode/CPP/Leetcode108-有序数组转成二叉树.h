#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 总是选择中间位置左边的数字作为根节点
        //考虑越界的问题
        int mid = left + (right-left)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

//迭代的方法
#include <queue>
using std::queue;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(0);   // 初始根节点
        queue<TreeNode*> nodeQue;           // 放遍历的节点
        queue<int> leftQue;                 // 保存左区间下表
        queue<int> rightQue;                // 保存右区间下表
        nodeQue.push(root);                 // 根节点入队列
        leftQue.push(0);                    // 0为左区间下表初始位置
        rightQue.push(nums.size() - 1);     // nums.size() - 1为右区间下表初始位置

        while (!nodeQue.empty()) {
            TreeNode* curNode = nodeQue.front();
            nodeQue.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();
            int mid = left + ((right - left) / 2);

            curNode->val = nums[mid];       // 将mid对应的元素给中间节点

            if (left <= mid - 1) {          // 处理左区间
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }

            if (right >= mid + 1) {         // 处理右区间
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }
        return root;
    }
};


class Solution2 {
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