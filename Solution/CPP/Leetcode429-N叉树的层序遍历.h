
#include <vector>
#include <queue>
using namespace std;
//define datastruct
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        que.push(root);
        vector<vector<int>> res;
        while(!que.empty()){
            //1.拿出这一层所有的节点
            int size = que.size();
            vector<int> vec;
            for(int i =0;i<size;i++){
                auto tmp = que.front();
                que.pop();
                vec.push_back(tmp->val);
                for(int j = 0;j<tmp->children.size();j++){
                    //2.将当前节点的孩子加入队列的尾部
                    if(tmp->children[j]) que.push(tmp->children[j]);
                }
            }
            //拿到了当强的所有的节点
            //压入result
            res.push_back(vec);
        }
        return res;
    }
};
