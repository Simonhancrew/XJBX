#include<cmath>
#include<algorithm>
using namespace std;
//递归的方法是最简单的，首先思考树平衡的条件，左右树的高度差不能超过1，这就需要一个判断树高的函数。
//然后我们递归的判断左子树和右子树的高度。最后就可以得到当前节点的最大高度。基准条件，到达空节点，返回高度0
//之后的Solution主函数，判断节点左树和右树的高度差是否大于1，是的话直接返回false;否则，继续递归判断左儿子和右儿子。
//最后需要考虑一些边界条件，树空时，直接返回true
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(maxdepth(root->left)-maxdepth(root->right))>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
private:
    int maxdepth(TreeNode *Node){
        if(Node == NULL) return 0;
        return max(maxdepth(Node->left),maxdepth(Node->right))+1;
    }
};