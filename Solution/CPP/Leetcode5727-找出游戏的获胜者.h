class Solution {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int n):val(n),next(nullptr){}
    };
    int findTheWinner(int n, int k) {
        ListNode* head = new ListNode(1);
        auto tmp = head;
        for(int i = 2;i <= n;i++){
            ListNode* cur = new ListNode(i);
            tmp->next = cur;
            tmp = cur;
        }
        tmp -> next = head;
        auto pre = tmp;
        int res = n;
        auto begin = head;
        while(res > 1){
            for(int i = 1; i < k;i++){
                pre = pre -> next;
                begin = begin->next;
            }
            pre ->next = begin->next;
            begin = begin ->next;
            res--;
        }
        return begin -> val;
    }
};