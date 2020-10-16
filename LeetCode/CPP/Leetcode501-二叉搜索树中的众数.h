#include "ADT.hpp"
#include <vector>
#include <stack>
using namespace std;
//递归中序
class Solution {
private:
    int maxCount; // 最大频率
    int count; // 统计频率
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return ;

        searchBST(cur->left);       // 左
                                    // 中
        if (pre == NULL) { // 第一个节点
            count = 1;
        } else if (pre->val == cur->val) { // 与前一个节点数值相同
            count++;
        } else { // 与前一个节点数值不同
            count = 1;
        }
        pre = cur; // 更新上一个节点

        if (count == maxCount) { // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount) { // 如果计数大于最大值频率
            maxCount = count;   // 更新最大频率
            result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // 右
        return ;
    }

public:
    vector<int> findMode(TreeNode* root) {
        count = 0; 
        maxCount = 0;
        TreeNode* pre = NULL; // 记录前一个节点
        result.clear();

        searchBST(root);
        return result;
    }
};

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


//如果不是一颗二叉搜索树呢？
//遍历这个树，拿到map，然后按照value排序
#include <unordered_map>
#include <algorithm>
class Solution {
private:

    void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // 前序遍历
        if (cur == NULL) return ;
        map[cur->val]++; // 统计元素频率
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return ;
    }
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map; // key:元素，value:出现频率
        vector<int> result;
        if (root == NULL) return result;
        searchBST(root, map);
        //单纯的map无法给value排序的
        //转成vec
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp); // 给频率排个序
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) { 
            // 取最高的放到result数组中
            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};