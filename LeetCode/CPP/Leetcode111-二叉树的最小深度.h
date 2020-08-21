#include "ADT.hpp"
#include <algorithm>
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int mindeep;
        int leftDepth,rightDepth;
        leftDepth = minDepth(root->left);
        rightDepth = minDepth(root->right);
        if(leftDepth == 0 && rightDepth == 0){
            mindeep = 1;
        }else if(leftDepth!=0&&rightDepth!=0){
            mindeep = std::min(leftDepth,rightDepth)+1;
        }else{
            mindeep = std::max(leftDepth,rightDepth)+1;
        }
        return mindeep;
    }
};