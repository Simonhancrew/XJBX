#include "ADT.hpp"
#include <climits>
#include <algorithm>

//root安装或者不安装
/*
状态 a：root必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
状态 b：覆盖整棵树需要的摄像头数目，无论root是否放置摄像头。
状态 c：覆盖两棵子树需要的摄像头数目，无论节点root本身是否被监控到。
对于root的左右节点的状态就有(la,lb,lc),(ra,rb,rc)
所以对于root a = lc+rc+1  b = min(a,min(la+rb,ra+lb)) c = min(a,lb+rb)

考虑到遍历到空子叶节点，不能放置监控，赋一个大整数给此处避免安装
*/
struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};