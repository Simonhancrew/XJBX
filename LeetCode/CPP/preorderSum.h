class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;//防止反复初始化数组 
    void dfs(TreeNode* root,int sum){
        int resum=sum-root->val;
        temp.push_back(root->val);
        if(resum==0&&!root->left&&!root->right)
			res.push_back(temp);//找到答案 
        if(root->left)
			dfs(root->left,resum);
        if(root->right)
			dfs(root->right,resum);
        temp.pop_back();//回溯 
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root)dfs(root,sum);
        return res;
    }
};