#include "ADT.hpp"
#include <algorithm>
using namespace std;
//1.如果当前节点的左右节点都是nullptr,高度就是1
//2.当前节点为nullptr，递归的结束条件
//3.有一个节点为空，考虑另一节点的高度
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

//迭代遍历，层次遍历每一层
//利用标记位提前中断
//
#include <queue>
class Solution2 {
public:
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        int depth = 0;
        //遇到最小的层深度，提前中断标志
        int flag = 0;
        if(root != nullptr) que.push(root); 
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i =0;i<size;i++){
                auto tmp = que.front();
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
                if(tmp->left == nullptr && tmp->right == nullptr){
                    //某一层的左右孩子都为0，说明此时就是最小的层深
                    flag = 1;
                    break;
                }
            }
            //如果已经找到最小的层深
            if(flag == 1){
                break;
            }
        }
        return depth;
    }
};