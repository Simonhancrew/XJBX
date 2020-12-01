#include <vector>
#include "ADT.hpp"
using namespace std;
class Solution {
public:
    void DFS(Node* root,vector<int> &res){
        if(root == nullptr){
            return;
        }
        int n = root->children.size();
        for(int i =0;i<n;i++){
            DFS(root->children[i],res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        DFS(root,res);
        return res;
    }
};
//后序，左右中，先压头，然后压左边，然后右边。最后reverse
#include <stack>
#include <algorithm>
class Solution2 {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()){
            auto tmp = stk.top();
            stk.pop();
            if(tmp != nullptr) res.push_back(tmp->val);
            else continue;
            int n = tmp->children.size();
            for(int i = 0;i<n;i++){
                stk.push(tmp->children[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};