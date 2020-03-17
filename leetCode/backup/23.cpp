https://leetcode.com/problems/merge-k-sorted-lists/submissions/

//两种解法
//一种是one by one 
//一种是分而治之
//借用了两个链表合并的函数

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//先用一个笨办法，从vector 尾部，一个一个来
//在这个基础上，改造成分而治之
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0){
            return nullptr;
        }
        /*
        ListNode* last = lists[0];
        for( int i = 1 ; i < lists.size(); i++){
            ListNode* cur = lists[i];
            last = listMerge(last,cur);
        }*/
        ListNode* last = mergeKListsInner(lists, 0, lists.size() -1);
        return last;
    }

    ListNode*  mergeKListsInner(vector<ListNode*>& lists, int begin, int end ){
        if( end == begin ){
            return lists[begin];
        }
        if( end - begin == 1){
            return listMerge(lists[begin], lists[end]);
        }

        int mid = (begin+end)/2;
        ListNode* left = mergeKListsInner(lists, begin, mid);
        ListNode* right = mergeKListsInner(lists, mid+1, end);
        return listMerge(left,right);
    }

    //两个有序的合并
    ListNode* listMerge(ListNode* l1, ListNode* l2){
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
