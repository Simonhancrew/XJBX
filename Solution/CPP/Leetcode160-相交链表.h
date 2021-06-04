#include <unordered_map>
#include "ADT.hpp"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        auto cur = headA;
        while(cur){
            mp[cur]++;
            cur = cur->next;
        }
        cur = headB;
        while(cur){
            if(mp.count(cur)) return cur;
            cur = cur->next;
        }
        return NULL;
    }
};


class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        auto curA = headA,curB = headB;
        while(curA != curB){
            curA = curA == nullptr?headB:curA->next;
            curB = curB == nullptr?headA:curB->next;
        }
        return curA;
    }
};