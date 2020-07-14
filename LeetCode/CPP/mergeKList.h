#pragma once
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

bool cmp(const ListNode* a, const ListNode* b) {
    return a->val < b->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> alllist;
        for (auto i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while (head) {
                alllist.push_back(head);
                head = head->next;
            }
        }
        if (alllist.size() == 0) return NULL;
        sort(alllist.begin(), alllist.end(), cmp);
        for (auto i = 1; i < alllist.size(); i++) {
            alllist[i - 1]->next = alllist[i];
        }
        alllist[alllist.size() - 1]->next = NULL;
        return alllist[0];
    }
};