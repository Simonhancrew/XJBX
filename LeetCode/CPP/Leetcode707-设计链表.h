#include "ADT.hpp"
//链表的删除可以考虑加入哑节点，回方便很多。这样头节点就不用单独处理

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _size = 0;
        dummy = new ListNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        //index无效就返回 -1
        if(index > (_size - 1) || index < 0){
            return -1;
        }
        ListNode* cur = dummy->next;
        //找的是index的位置
        //注意cur--
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto newHead = new ListNode(val);
        newHead->next = dummy->next;
        dummy->next = newHead;
        ++_size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto newNode = new ListNode(val);
        auto cur = dummy;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index >_size){
            return;
        }
        auto newNode = new ListNode(val);
        auto cur = dummy;
        //之后cur位于index之前的位置
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++_size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        auto cur = dummy;
        while(index--){
            cur = cur->next;
        }
        //删除别忘删除资源
        auto tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    int _size;
    //哑节点的设计是为了方便删除
    ListNode* dummy;
};
