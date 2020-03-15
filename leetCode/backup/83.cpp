https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* p = head;
        ListNode* last = head;
        int lastval = p->val;
        p = p->next;
        while(p != nullptr){
            if( p->val == lastval){
                last->next = p->next;
            }else{
                last = p ;
            }
            lastval = p->val;
            p = p->next;
        }
        return head;
    }
};
