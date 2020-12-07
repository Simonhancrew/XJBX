#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
//DFS
class Solution{
public:
    Node* cloneGraph(Node* node){
        if(node == nullptr){
            return node;
        }
        unordered_map<Node*,Node*> visited;
        //一定要先于循环判断，不然可能循环。
        if(visited.find(node) != visited.end()){
            return node;
        } 
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        //更新邻居
        for(auto neighbor:node->neighbors){
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
//BFS
//用一个hashmap储存之前node到现在node的映射。
#include<queue>
class solution{
    Node* cloneGraph(Node* node){
        if(node == nullptr){
            return node;
        }
        unordered_map<Node*,Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while (!Q.empty())
        {
            auto n = Q.front();
            Q.pop();
            for(auto neighbor:node->neighbors){
                if(visited.find(neighbor)==visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    Q.push(visited[neighbor]);
                }
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    } 
};