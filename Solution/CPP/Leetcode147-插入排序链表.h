#include "ADT.hpp"
//有序区和无序区，加入dummy方便头节点之前插入
//然后进行模拟就可以了，找到插入节点在有序区中的位置
//复杂度n*n
class Solution {
public:
    ListNode* insertionSortList(ListNode* head){
        if(head == nullptr){
            return head;
        }
        ListNode* dummyhead = new ListNode(0);
        dummyhead -> next = head;
        ListNode* lastSort = head;
        ListNode* cur = head -> next;
        while(cur != nullptr){
            //>=，维持字典序
            if(cur->val >= lastSort->val){
                cur = cur -> next;
                lastSort = lastSort->next;
            }else{
                ListNode* prev = dummyhead;
                //注意<=，维持字典序
                while(prev->next->val <= cur->val){
                    prev = prev->next;
                }
                lastSort->next = cur->next;
                cur->next = prev->next;
                prev->next = cur; 
                cur = lastSort->next;
            }
        }
        return dummyhead -> next;
    }
};