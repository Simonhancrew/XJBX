/*
有以下五种情况：
第一种情况：没找到删除的节点，遍历到空节点直接返回了.
第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，
            返回删除节点右孩子为新的根节点。
        或者将右子树的最小值和root交换，之后递归的删除交换后值的节点    
*/
#include "ADT.hpp"
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        //这里相当于把新的节点返回给上一层，上一层就要用 root->left 或者 root->right接住
        if(key < root -> val){ // 找到key所在的位置
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        if(key > root -> val){ // 找到key所在的位置
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        // 当key == root -> val， 即找到目标点时
            //当目标点只有一边子树时
        if(!root -> left){ // 若没有左子树，删除目标点，右子树接上
            TreeNode* temp = root -> right;
            delete(root);
            return temp;
        }
        if(!root -> right){ // 若没有右子树，删除目标点，左子树接上s
            TreeNode* temp = root -> left;
            delete(root);
            return temp;
        }
            //当目标点左右都有子树时
        TreeNode* temp = root -> right; // 找到右子树中最小的值，即进入右子树后一直向左遍历
        while(temp -> left) temp = temp -> left;
        swap(root -> val, temp -> val); // 交换值
        root -> right = deleteNode(root -> right, key); // 进入遍历，删除key
        return root;
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if (root->val == key) {
            // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            if (root->left == nullptr) return root->right; 
            // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) return root->left; 
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else {  
                TreeNode* cur = root->right; // 找右子树最左面的节点
                while(cur->left != nullptr) { 
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};


//迭代法
class Solution {
private:
    // 将目标节点（删除节点）的左子树放到 目标节点的右子树的最左面节点的左孩子位置上
    // 并返回目标节点右孩子为新的根节点
    // 是动画里模拟的过程
    TreeNode* deleteOneNode(TreeNode* target) {
        if (target == nullptr) return target;
        if (target->right == nullptr) return target->left;
        TreeNode* cur = target->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        TreeNode* cur = root;
        TreeNode* pre = nullptr; // 记录cur的父节点，用来删除cur
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (pre == nullptr) { // 如果搜索树只有头结点
            return deleteOneNode(cur);
        }
        // pre 要知道是删左孩子还是右孩子
        if (pre->left && pre->left->val == key) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right && pre->right->val == key) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};