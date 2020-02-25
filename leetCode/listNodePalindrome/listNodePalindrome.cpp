#include <stdio.h> 
#include <string>  
#include <vector>  
#include <iostream>  
//https://blog.csdn.net/notHeadache/article/details/52401231
//链接回文 判断

class ListNode {
		public:
      int val;
      ListNode* next;
      ListNode(int x) { val = x; next = nullptr; }
      ListNode() {  next = nullptr; }
};


using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* nextNode = head->next;
        ListNode* pre = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            pre = slow;
            slow = nextNode;
            nextNode = nextNode->next;
            slow->next = pre;
        }
        if(fast->next == nullptr){
            slow = pre;
        }
        while(nextNode != nullptr){
            if(slow->val != nextNode->val) return false;
            slow = slow->next;
            nextNode = nextNode->next;
        }
        return true;
    }
};


int main(int argc, char**argv){

		vector<int>    s = {4,5,6,7,8,7,6,5,4};
		ListNode* pHead ;
		ListNode* pre = pHead;
		for( auto i : s )
		{
				ListNode* p = new ListNode(i);
				if(pre == nullptr) {
						pHead = p;
				}
				else{
						pre->next = p ;
				}
				pre = p ;
		}
		Solution ss; 
		cout << ss.isPalindrome(pHead) << endl;
}
