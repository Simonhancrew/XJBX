class Solution {
/*递归解法，为空就直接返回，否则判断哪一个小，然后递归决定下一个进入结果里的节点，有一个为空则结束*/
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }else if (l2 == nullptr ){
            return l1;
        }else if (l1->val < l2->val){
            l1 -> next = mergeTwoLists(l1->next,l2);
            return l1;
        }else {
            l2 -> next = mergeTwoLists (l1,l2 -> next);
            return l2;
        }
    }
};


class Solution2 {
/*当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，
将较小值的节点添加到结果里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位首先，我们设定一个哨兵节点 prehead ，
这可以在最后让我们比较容易地返回合并后的链表。我们维护一个 prev 指针，我们需要做的是调整它的 next 指针。然后，我们重复以下过程，
直到 l1 或者 l2 指向了 null ：如果 l1 当前节点的值小于等于 l2 ，我们就把 l1 当前的节点接在 prev 节点的后面同时将 l1 指针往后移一位
否则，我们对 l2 做同样的操作。不管我们将哪一个元素接在了后面，我们都需要把 prev 向后移一位。
在循环终止的时候， l1 和 l2 至多有一个是非空的。
由于输入的两个链表都是有序的，所以不管哪个链表是非空的，它包含的所有元素都比前面已经合并链表中的所有元素都要大。
这意味着我们只需要简单地将非空链表接在合并链表的后面，并返回合并链表即可。
*/
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* prehead = new ListNode(-1);
       ListNode* prev = prehead;
       while (l1 != nullptr && l2 != nullptr){
           if (l1->val < l2->val){
               prev -> next = l1;
               l1 = l1-> next;
           }else{
            prev -> next = l2;
            l2 =l2 -> next;
           }
            prev = prev->next;
       }
       prev->next = l1 == nullptr ? l2 : l1;
       return prehead->next;
    }
};
