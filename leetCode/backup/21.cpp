https://leetcode.com/problems/merge-two-sorted-lists/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( l1 == nullptr){
            return l2;
        }
        if( l2 == nullptr){
            return l1;
        }

        ListNode d(0);

        d.next = l1;// 指向l1

        ListNode* last = &d;

        while (l1 != nullptr && l2 != nullptr){
            if( l1->val <= l2->val){
                last = l1;
                l1 = l1->next;
            }else{
                ListNode* l2next = l2->next;
                last->next = l2;
                l2->next = l1;
                last = l2;
                l2 = l2next;
            }
            /* 这里有两个思路，上面是按l1 做作
            注释的以head 做主。一个一个串
            if( p1->val <= p2->val ){
                head->next = p1;
                p1 = p1->next;
                head = head->next;
            }
            else{
                head->next = p2;
                p2 = p2->next;
                head = head->next;
            }*/
        }
        if( l1 == nullptr){
            last->next = l2;
        }
        if( l2 == nullptr){
            last->next = l1;
        }

        return d.next;
    }
};
