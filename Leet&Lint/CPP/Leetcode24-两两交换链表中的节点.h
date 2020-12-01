#include "ADT.hpp"
#include <vector>
using namespace std;
//三次遍历，额外空间数组
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        vector<int> cur;
        if(!head){
            return head;
        }
        auto tmp = head;
        while(tmp){
            cur.push_back(tmp->val);
            tmp=tmp->next;
        }
        int n = cur.size();
        if(n==1){
            return head;
        }
        for(int i = 0;i<n-1;i = i+2){
            swap(cur[i],cur[i+1]);
        }
        head = new ListNode(cur[0]);
        tmp = head;
        for(int i =1;i<n;i++){
            tmp->next = new ListNode(cur[i]);
            tmp = tmp->next;
        }
        return head;
    }
};
//递归的思路，两两实现，递归执行
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //终止条件就是节点不够了
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        //对于两个节点而言的新头
        ListNode* newHead = head->next;
        //原头的next
        head->next = swapPairs(newHead->next);
        //替换新头
        newHead->next = head;
        return newHead;
    }
};
//迭代的方式，没有额外的空间复杂度
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
    }
};