#include "../base.h"
using namespace std;

//两个有序的合并 
ListNode* listMerge(ListNode* l1, ListNode* l2){
	if( l1 == nullptr ){
		return l2;
	}
	if( l2 == nullptr){
		return l1;
	}

	ListNode dummy;
	dummy.next = l1;
	ListNode* l1last = &dummy ;
	ListNode* l2last = l2 ;
	//我们最终要把数据合并到l1上面去

	while( l1 != nullptr && l2 != nullptr){
		ListNode* l1next  = l1->next;
		ListNode* l2next  = l2->next;
		if( l1->val <= l2->val){
			l1last = l1;
			l1 = l1next;
		}else{
			l1last->next = l2;
			l2->next = l1;
			l2last = l2;
			l1last = l2;
			l2 = l2next;
		}
	}

	if( l1 == nullptr && l2 == nullptr){
		return dummy.next;
	}
	if( l1 != nullptr){
		//不用处理啊
	}
	if( l2 != nullptr){
		l1last->next = l2;
	}
	return dummy.next;

	//这地方可以用递归？
}
ListNode* listMerge2(ListNode* p1, ListNode* p2){
	if( p1 == nullptr){
		return p2;
	}
	if( p2 == nullptr){
		return p1;
	}
	if( p1 == p2 ){
		return p1;
	}
	ListNode dummy;
	ListNode* head = &dummy;
	ListNode* result = &dummy;
	while( p1 != nullptr && p2 != nullptr){
		if( p1->val <= p2->val ){
			head->next = p1;
			head = p1;
			p1 = p1->next;
		}
		else{
			head->next = p2;
			head = p2;
			p2 = p2->next;
		}
	}
	if( p1 != nullptr){
		head->next = p1;
	}
	if( p2 != nullptr){
		head->next = p2;
	}
    return result->next;
}







int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num1 = 10;
    int num2 = 10;
    if( argc > 2 ){
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
    }
    vector<int> link1  = (makeRandVec(num1));

    vector<int> link2  = (makeRandVec(num2));


	std::sort(link1.begin(), link1.end());
	std::sort(link2.begin(), link2.end());

    ListNode* p1 = makeList(link1);
    ListNode* p2 = makeList(link2);
    cout << "p1\n " ;  outputListNode(p1);
    cout << "p2\n "; outputListNode(p2);
	ListNode* p3 = listMerge(p1,p2);
	outputListNode(p3);

    ListNode* p5 = makeList(link1);
    ListNode* p6 = makeList(link2);
	ListNode* p4 = listMerge2(p5,p6);
	outputListNode(p4);
    return 0;
}
