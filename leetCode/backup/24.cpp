https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        //哑节点
        if( head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* last = &dummy;
        ListNode* first = head;
        ListNode* second = head->next;

        while( first != nullptr){
            second = first->next;
            if(second ==nullptr){
                break;
            }
            ListNode* next = second->next;
            last->next = second;
            first->next = next;
            second->next = first;

            last = first;
            first = next;
        }
        return dummy.next;
    }
};





