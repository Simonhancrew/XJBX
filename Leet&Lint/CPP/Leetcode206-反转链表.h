#include "ADT.hpp"
//双指针的方法去就地反转
//链表的反转需要考虑三个部分 
//1.当前到那个节点了(cur)
//2.当前节点的前驱是谁(pre)
//3.当前节点的后继是谁，因为断开了连接，所以要维护这个信息以便后续往前推进(tmp)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};