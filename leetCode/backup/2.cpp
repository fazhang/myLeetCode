https://leetcode.com/problems/add-two-numbers/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;//就取l1 来做head
        int carry = 0 ;
        ListNode* last = nullptr;
        while (l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;

            l1->val = sum%10; //尾数
            carry = sum/10; //进位
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        //到这里，肯定就有一个走到了尾部
        if(l1 == nullptr){
            //把l2 的尾部拼接过来
            last->next = l2;
           // l2->val = l2->val + carry;
        }
        ListNode* lastleft = last;
        last = last->next;
        while(last != nullptr){
            int sum  = last->val + carry;
            last->val = sum%10;
            carry  = sum/10;
            lastleft = last;
            last = last->next;
        }
        if( carry != 0){
        //末尾还要加一个
            ListNode* tail = new ListNode(carry);
            tail->next = nullptr;
            lastleft->next = tail;
        }
        return head;
    }
};
