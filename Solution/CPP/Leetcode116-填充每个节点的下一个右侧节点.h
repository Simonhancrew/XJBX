class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//朴实无华，层序遍历。
#include <queue>
using std::queue;
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        auto tmp = root;
        if(tmp == nullptr){
            return root;
        }
        que.push(tmp);
        while(!que.empty()){
            int n = que.size();
            for(int i = 0;i<n;++i){
                auto node = que.front();
                que.pop();
                if(i == n-1){
                    node->next = nullptr;
                }else{
                    node->next = que.front();
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
};