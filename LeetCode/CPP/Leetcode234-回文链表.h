//找到中点？->快慢指针
//中点的值没办法寻地址访问？->逆序第二部分的链表
#include "ADT.hpp"
class Solution {
public:
    bool isPalindrome(ListNode *head){
        if(head == nullptr) return true;
        auto firstEnd = endOfFirsthalf(head);
        //第二部分的链表完全求逆
        auto secondStart = reverse(firstEnd->next);
        bool res = true;
        auto p1 = head;
        auto p2 = secondStart;
        //注意扣边界和结束的条件
        while(res && p2 != nullptr){
            if(p1->val != p2->val){
                res = false;
                //要还原链表不能直接return
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        firstEnd->next = reverse(secondStart);
        return res;
    }
private:
    //快慢指针找到中点
    ListNode* endOfFirsthalf(ListNode* head){
        ListNode* slow,*fast;
        slow = head,fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //链表逆序，返回新头
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            //记录cur的原指向
            auto tmp = cur->next;
            cur ->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};