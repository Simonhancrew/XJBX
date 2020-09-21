#include "ADT.hpp"
#include <vector>
using namespace std;
class Solution {
public:
    //逆中序递归，得到一个从小到大的序列
    //sum设置成类pub，不断更新每一个节点的值
    int sum = 0;    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root != nullptr){
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

//morris遍历

class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root){
        
    }
};