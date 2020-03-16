https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       //链表操作，一般都是双指针来处理


        ListNode dummy;
        dummy.next = head;// 还是搞一个哑节点好一些

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = &dummy;

        while(fast != nullptr && n > 0){
            fast = fast->next;
            n--;
        }
        while( fast != nullptr){
            fast = fast->next;
            slow = slow->next;
            last = last->next;
        }
        last->next = last->next->next;
        return dummy.next;
    }
    //别急， 如果只有两个值呢？
};

