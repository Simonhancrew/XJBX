struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), father(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if(p->right){
            p = p->right;
            while(p->left){
                p = p->left;
            }
            return p;
        }
         
        while(p->father && p == p->father->right) p = p->father;
        return p->father;
    }
};