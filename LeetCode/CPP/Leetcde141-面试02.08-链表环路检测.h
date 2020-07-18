
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr)} { }
    /* data */
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = nullptr;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(!fast){
                return nullptr;
            }
            fast = fast->next;
            if(fast == slow){
                meet = fast;
                break;
            }
        }
        if(meet == nullptr){
            return nullptr;
        }
        while(head && meet){//从头节点和快慢指针相交节点一起同速度出发，相交处就是环的起点
            if(meet == head){
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return nullptr;
    }
};