#include "ADT.hpp"
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        DFS(root, "", result);
        return result;
    }

private:
    //path要做拷贝传进去,不然就要回溯
    void DFS(TreeNode *root, string path, vector<string> &result)
    {
        if (root != nullptr)
        {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                result.push_back(path);
            }
            else
            {
                path += "->";
                DFS(root->left, path, result);
                DFS(root->right, path, result);
            }
        }
    }
};
//递归带回溯
class Solution {
private:

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // 这才到了叶子节点
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};


class Solution2
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> results;
        if (root == nullptr)
        {
            return results;
        }

        queue<TreeNode *> node_que;
        queue<string> path_que;

        node_que.push(root);
        path_que.push(to_string(root->val));

        while (!node_que.empty())
        {
            TreeNode *node = node_que.front();
            string path = path_que.front();

            node_que.pop();
            path_que.pop();

            if (node->left == nullptr && node->right == nullptr)
            {
                results.push_back(path);
            }
            else
            {
                if (node->left != nullptr)
                {
                    node_que.push(node->left);
                    path_que.push(to_string(node->left->val));
                }

                if (node->right != nullptr)
                {
                    node_que.push(node->right);
                    path_que.push(to_string(node->right->val));
                }
            }
        }
        return results;
    }
};