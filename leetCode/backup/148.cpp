https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        return quickSort(head,nullptr);
    }
    void myswap(ListNode* ipre, ListNode*& jpre ){
    if( ipre == jpre ){
        return ;
    }
    ListNode* i = ipre->next; ListNode* j = jpre->next;
    ListNode* inext = i->next; ListNode* jnext = j->next;

    if( ipre->next == jpre ){
        ipre->next = j;
        j->next = i ;
        i->next = jnext;
        jpre = ipre->next;
        return ;
    }
    ipre->next = j; j->next = inext;
    i->next = jnext; jpre->next = i;
}
    ListNode* quickSort( ListNode* p , ListNode* end){
    if( p == nullptr ){ return p; }
    if( p == end ){ return p; }
    if( p->next == end  ){ //只有一个元素了
        return p;
    }
    ListNode* head = p ; int pval = p->val ;
    ListNode* i = p ; ListNode* j = p->next;
    ListNode  dummy(0); dummy.next = p ;
    ListNode* ipre = &dummy; ListNode* jpre = p;
    int iindex = 0; int jindex = 1;

    for( ; i != end && j != end ; ){
        if( j->val < pval ){
            ipre = i; i = i->next;
            myswap(ipre,jpre);
            i = ipre->next; j = jpre->next;
        }
        jpre = j ; j = j->next;
    }
    ListNode* ppre = &dummy;
    myswap(ppre, ipre);
    p = ppre->next;
    i = ipre->next;
    if( i == end ){
        return p;
    }
    ListNode* right = quickSort(i->next, end);
    i->next = right;
    ListNode* left = quickSort(p , i->next);
    return left;
}
};

static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
