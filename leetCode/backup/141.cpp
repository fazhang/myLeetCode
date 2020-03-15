https://leetcode.com/problems/linked-list-cycle/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while( fast != nullptr){
            fast = fast->next;
            if( fast == nullptr){
                return false;
            }

                fast = fast->next;

            slow = slow->next;
            if( fast == slow){
                return true;
            }
        }
        return false;
    }
};
