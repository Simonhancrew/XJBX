#include "ADT.hpp"
//小技巧，在头部加入哑节点
//可以省去判断头节点是否要删除
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next =head;
        auto cur = dummy;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                auto tmp = cur ->next;
                cur->next = tmp->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

//不使用dummy
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        //删除头部的节点
        while(head != nullptr && head->val == val){
            auto tmp = head;
            head = head ->next;
            delete tmp;
        }
        auto cur = head;
        //删除非头部的节点
        while(cur != nullptr && cur ->next != nullptr){
            if(cur ->next->val == val){
                auto tmp = cur ->next;
                cur ->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};