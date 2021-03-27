#include "ADT.hpp"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //后k个节点移到前面
        if(!head) return head;
        int n = 0;
        auto ptr = head;
        while(ptr){
            n++;
            ptr = ptr->next;
        }
        k %= n;
        if(!k) return head;
        //跳n-k-1次到end
        auto end = head;
        for(int i = 0;i < n-k-1;i++) end = end->next;
        auto first = head;
        while(first->next){
            first = first->next;
        } 
        first->next = head;
        head = end->next;
        end ->next = nullptr;
        return head;
    }
};


//快慢指针，不用自己找规律
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto ptr = head;
        if(!head) return head;
        int n = 0;
        while(ptr){
            ptr = ptr->next;
            n++;
        }
        k %= n;
        if(k == 0){
            return head;
        }
        auto first = head,end = head;
        //先走k步
        while(k-- && first){
            first = first->next;
        }
        //end再走n-k步
        while(first ->next){
            first = first->next;
            end = end->next;
        }
        first->next = head;
        head = end->next;
        end->next = nullptr;
        return head;
    }
};