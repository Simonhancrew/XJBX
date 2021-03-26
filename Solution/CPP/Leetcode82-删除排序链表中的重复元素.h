#include "ADT.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        auto pre = dummy,cur = head,after = head ->next;
        while(cur != nullptr){
            if(!after){
                return dummy->next;
            }
            if(cur->val == after->val){
                while(after && cur->val == after->val ){
                    after = after->next;
                }
                pre->next = after;
                cur = after;
                if(cur){
                    after = cur->next;
                }
            }else{
                pre = cur;
                cur = after;
                if(after){
                    after = after->next;
                }
            }
        }
        return dummy->next;
    }
};


//更好的解法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy  = new ListNode(-1);
        dummy->next = head;
        auto ptr = dummy;
        //维护一个当前节点的下一节点
        //找到一段相等的点（如果有的话），跳过他
        //没有的话就往前推进
        while(ptr->next){
            auto cur = ptr->next;
            while(cur && ptr->next->val == cur->val){
                cur = cur->next;
            }
            if(cur == ptr->next->next) ptr = ptr->next;
            else ptr->next = cur;
        }
        return dummy->next;
    }
};