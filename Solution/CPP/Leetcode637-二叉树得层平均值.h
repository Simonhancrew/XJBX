#include <vector>
#include <queue>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            double level = 0;
            int size =que.size();
            //广度中一次将本层全部提取得手法
            for(int i = 0;i<size;i++){
                TreeNode *cur = que.front();
                que.pop();
                level +=cur->val;
                if(cur->left){
                    que.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                } 
            }
            result.push_back(level/size);
        }
        return result;
    }
};

//深度优先搜索，要记录一个每层节点数的数组count
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> sum;
        DFS(root,0,count,sum);
        int size = sum.size();
        vector<double> ave;
        for(int i =0;i<size;i++){
            ave.push_back(sum[i]/count[i]);
        } 
        return ave;
    }
private:
    void DFS(TreeNode* root,int level,vector<int> &counts,vector<double> &sum){
        if(root == nullptr){
            return;
        }
        if(level<sum.size()){
            sum[level] +=root->val;
            counts[level]++;
        }else{
            sum.push_back(static_cast<double>(root->val));
            counts.push_back(1);
        }
        DFS(root->left,level+1,counts,sum);
        DFS(root->right,level+1,counts,sum);
    }
};