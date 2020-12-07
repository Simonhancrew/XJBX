#include "ADT.hpp"
#include <vector>
using std::vector;
//trick,针对于链表的处理
//针对头节点，添加一个新头
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto tmp = dummy;
        while(tmp){
            node.push_back(tmp);
            tmp = tmp->next;
        }
        int size = node.size();
        int pre = size-n-1;
        node[pre]->next = node[pre]->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

//由于我们需要找到倒数第n个节点，因此我们可以使用两个指针first和second同时对链表进行遍历，
//并且first比second超前n个节点。当first遍历到链表的末尾时，second就恰好处于倒数第n个节点。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};