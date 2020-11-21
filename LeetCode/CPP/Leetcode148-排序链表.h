#include "ADT.hpp"
#include <algorithm>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        auto tmp = head;
        vector<ListNode*> vec;
        while(tmp != nullptr){
            vec.push_back(tmp);
            tmp = tmp->next;
        }
        sort(vec.begin(),vec.end(),[](ListNode* lhs,ListNode* rhs){
            return (lhs->val < rhs->val);
        });
        for(int i = 0;i < vec.size() - 1;++i){
            vec[i]->next = vec[i+1];
        }
        vec[vec.size() - 1] ->next = nullptr;
        return vec[0];
    }
};

//满足题意的要求，归并，快排，堆排
//满足空间要求的话就是归并
class Solution {
public:
    ListNode* sortList(ListNode* head){
        return sortList(head,nullptr);
    }
    //归并两个有序链表
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy = new ListNode(0);
        auto tmp = dummy;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val >= head2->val){
                tmp -> next = head2;
                //需要更进一步
                head2 = head2 -> next;
            }else{
                tmp -> next = head1;
                head1 = head1 -> next;
            }
            tmp = tmp -> next;
        }
        //链表和数组处理的不同
        if(head1 != nullptr){
            tmp -> next = head1;
        }else{
            tmp->next = head2;
        }
        return dummy -> next;
    }
    //重载sort  
    ListNode* sortList(ListNode* head,ListNode* tail){
        if(head == nullptr){
            return head;
        }
        //前闭后开
        if(head -> next == tail){
            head -> next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        //都和tail比看有没有达到终点
        while(fast != tail){
            slow = slow -> next;
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head,mid),sortList(mid,tail));
    }
};