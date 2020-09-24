#include "ADT.hpp"
#include <vector>
#include <stack>
using namespace std;
//迭代中序，顺序遍历有序的一组数，找到最多的元素
//有序数列遍历找众数的技巧，因为相同的数都被压缩在一起，可以不用hash
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        int lastnum = -1;//上一个数
        int maxtimes = 0;//最多的数个数
        int nowtimes = 0;//已经出现的次数
        while(root!=nullptr||stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            auto tmp = stk.top();
            stk.pop();
            if(lastnum == tmp->val) nowtimes++;
            else nowtimes = 1;
            
            if(nowtimes > maxtimes){//不管now和max是不是一个数，全部弹出然后处理
                ans.clear();
                ans.push_back(tmp->val);
                maxtimes = nowtimes;
            } 
            else if (nowtimes == maxtimes){
                ans.push_back(tmp->val);
            }
            lastnum = tmp->val;
            root = root->right;
        }
        return ans;
    }
};

//morris遍历
//morris遍历的特点就是每到一个节点，先去建立他的前驱节点和他的联系
//如果前驱节点已经和他建立了联系，说明左子树已经遍历完成，断开联系之后去遍历右子树
class Solution2 {
public:
    int base, count, maxCount;
    vector<int> answer;
    //有序数祖的众数
    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (!cur->left) {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return answer;
    }
};