#include "ADT.hpp"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto small = new ListNode(0);
        auto s = small;
        auto big = new ListNode(0);
        auto b = big;
        auto cur = head;
        while(cur != nullptr){
            if(cur->val < x){
                s->next = cur;
                s = s->next;
            }else{
                b->next = cur;
                b = b->next;
            }
            cur = cur->next;
        }
        b->next = nullptr;
        s->next = big->next;
        return small->next;
    }
};