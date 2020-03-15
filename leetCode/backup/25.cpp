https://leetcode.com/problems/reverse-nodes-in-k-group/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* p, int k) {
    //空指针，或者只有一个节点，就不用处理了
    if( k<= 1 || p == nullptr || p->next == nullptr ){
        return p;
    }
    ListNode dummy;
    dummy.next = p;
    ListNode* slow = p;
    ListNode* fast = slow;

    ListNode* last = &dummy;
    while( slow != nullptr){
        fast = slow;
        int m = k ;
        while( --m > 0 && fast != nullptr){
            fast = fast->next;
        }
        if( m !=  0 || fast == nullptr){
            break;
        }

        ListNode* pLast = nullptr ;
        ListNode* pNext = nullptr ;

        ListNode* head = slow ;//第一个节点

        ListNode* fastnext = nullptr;
        if( fast != nullptr){
            fastnext = fast->next;
        }
        while( slow != fastnext ){
            pNext = slow->next;
            slow->next = pLast;
            pLast = slow;
            slow = pNext;
        }
            slow = fastnext;
            head->next = fastnext;
            last->next = pLast;
            last = head;
    }
        return dummy.next;
    }
};
