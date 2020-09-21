#include <vector>
using namespace std;
class Node{
public:
    int val;
    vector<Node*> children;
    Node(){}
    Node(int _val){
        val = _val;
    }
    Node(int _val,vector<Node*> _chiledren){
        val = _val;
        children = _chiledren;
    }

};
//递归
class Solution {
public:
    vector<int> preorder(Node *root){
        vector<int> result;
        DFS(root,result);
        return result;
    }
private:
    void DFS(Node *root,vector<int> &result){
        if(root == nullptr){
            return;
        }
        result.push_back(root->val);
        int n = root->children.size();
        for(int i = 0;i < n;++i){
            DFS(root->children[i],result);
        }
    }
};

//迭代，先压栈最右边的
#include <stack>
class Solution2 {
public:
    vector<int> preordered(Node* root){
        vector<int> result;
        stack<Node*> stk;
        if(root == nullptr) return result;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            for(int i = tmp->children.size() - 1; i>=0;--i){
                stk.push(tmp->children[i]);
            }
        }
        return result;
    }
};