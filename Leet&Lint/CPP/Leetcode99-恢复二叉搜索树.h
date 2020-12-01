#include "ADT.hpp"
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;
//中序遍历计入数组，然后将数组变成有序，然后在bst中进行还原
class Solution1 {
public:
    
    void inorder(TreeNode*  root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    //找到不符合要求的两个数，有两种情况，第一种就是xy相邻对换，第二种xy不相邻兑换.
    //可以注意交换的手法,x=y=-1,然后y后置，判断x是否取值过
    pair<int,int> findThePair(const vector<int> &nums){
        int x = -1,y =-1;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                y = nums[i+1];
            }
            if(x == -1){
                x = nums[i];
            }
            else {
                break;
            }
        }
        return {x,y};
    }
    void recover(TreeNode* r, int count, int x, int y){
        if(r != nullptr){
            if(r->val == x||r->val == y){
                r->val = (r->val == x)?y:x;
                count--;
            }
            if(count == 0){
                return;
            }
            recover(r->left,count,x,y);
            recover(r->right,count,x,y);
        }
    }
    void recoverTree(TreeNode* root){
        inorder(root);
        pair<int,int> needSwaped = findThePair(nums);
        recover(root,2,needSwaped.first,needSwaped.second);
    }
private:
    vector<int> nums;
};
//中序遍历，自己压栈
class Solution3 {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->val < pred->val) {
                y = root;
                if (x == nullptr) {
                    x = pred;
                }
                else break;
            }
            pred = root;
            root = root->right;
        }

        swap(x->val, y->val);
    }
};

//morris遍历，不需要多余空间复杂度的一种优雅遍历，利用的节点的nullptr信息完成遍历
//一定要掌握
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};