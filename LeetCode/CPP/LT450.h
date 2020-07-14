class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
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