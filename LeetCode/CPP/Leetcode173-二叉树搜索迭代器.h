/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        vector<int> vec={};
        index = -1;
        _inordered(root);
    }
    
    /** @return the next smallest number */
    int next() {
        ++index;
        return vec[index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return vec.size()>index+1;
    }
private:
    void _inordered(TreeNode* root){
        if(root == NULL) return;
        _inordered(root->left);
        vec.push_back(root->val);
        _inordered(root->right);
    }
    vector<int> vec;
    int index;
};

//Stack
class BSTIterator2 {
public:
    BSTIterator(TreeNode* root) {
        _leftorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* most = sta.top();
        sta.pop();
        _leftorder(most->right);
        return most->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }
private:
    stack<TreeNode*> sta;
    void _leftorder(TreeNode* root){
        while(root!=NULL){
            sta.push(root);
            root = root -> left;
        }
    }
};