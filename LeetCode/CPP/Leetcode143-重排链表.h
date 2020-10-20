#include "ADT.hpp"
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        vector<ListNode*> vec;
        auto tmp = head;
        while(tmp){
            vec.push_back(tmp);
            tmp = tmp->next;
        }
        vector<ListNode*> res;
        int i = 0,j = vec.size()-1;
        while(i<j){
            res.push_back(vec[i]);
            res.push_back(vec[j]);
            ++i,--j;
        }
        if(i == j){
            res.push_back(vec[i]);
        }
        int n = vec.size()-1;
        for(int i = 0;i < n ;i++){
            res[i]->next = res[i+1];
        }
        res[n]->next = nullptr;
        return;
    }
};
//转线性表之后换
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};

//寻找链表中心+链表逆序+合并链表
//注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。
//找到原链表的中点->快慢指针来 
//将原链表的右半端反转
//因为两链表长度相差不超过1，因此直接合并
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};