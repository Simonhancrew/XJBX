#include<vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr)} { }
    /* data */
};

using namespace std;

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        return vec[vec.size()-k];
    }
    
    
    //两者速度差不多
    int KthTolast(ListNode* head, int k) {
        //用双指针做
        if(head == NULL)            //常规判断
            return 0;
        ListNode *pre = head;       //前指针
        ListNode *p = head;         //后指针    
        int i = 0;              //i用来确保后指针移动到第K个位置
        while(i < k){
            if(p == NULL)       
                return 0;
            p = p->next;
            i++;
        }
        while(p != NULL){       //相距K个，同步移动，直到后指针到链表尾部。
            pre = pre->next;
            p = p->next;
        }
        return pre->val;
    }
};