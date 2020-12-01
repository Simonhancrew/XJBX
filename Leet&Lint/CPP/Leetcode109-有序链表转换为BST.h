#include "ADT.hpp"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildtree(head, nullptr);
    }
private:
    //链表找到mid节点的方法之一，快慢指针
    ListNode* getmid(ListNode* left,ListNode* right){
        ListNode* slow = left;
        ListNode* fast = left;
        while(fast != right&&fast->next != right){
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    } 
    //注意基准条件，然后递归的buildtree
    TreeNode* buildtree(ListNode* left,ListNode* right){
        if(left == right){
            return nullptr;
        }
        ListNode* mid = getmid(left,right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildtree(left,mid);
        root->right = buildtree(mid->next,right);
        return root;  
    }
};
//bst的中序遍历就是升序的，假设二叉树存在，中序遍历，填入相应的链表节点。 
class Solution {
public:
    int getLength(ListNode* head) {
        int ret = 0;
        for (; head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
};

