/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//有random的链表深拷贝
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*,int> node_map;
        std::vector<Node*> node_vec;
        Node* ptr = head;
        int i = 0;
        while(ptr){
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(0);//记得处理vec中的尾节点，面的扣边界了
        ptr = head;
        i = 0;
        while (ptr){
            node_vec[i]->next = node_vec[i+1];
            if (ptr->random){
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};