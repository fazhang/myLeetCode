#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
using namespace std;

class ListNode {
		public:
      int val;
      ListNode* next;
      ListNode(int x) { val = x; next = nullptr; }
      ListNode() {  next = nullptr; }
};
ListNode*  makeList(const vector<int>& in){
    ListNode pHead ;
    ListNode* pre = &pHead;
    for( auto i : in )
    {
        ListNode* p = new ListNode(i);
        pre->next = p ;
        pre = p ;
    }
    return pHead.next;
}
uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
void outputVec(const vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
	cout << __func__ << endl;
    for( auto i : in){
        cout <<setiosflags(ios::left)<<setw(8);
        cout << i << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        cnt ++;
    }
    cout << endl;
}
vector<int> makeRandVec( int num, int mod=100){
    vector<int> out;
    out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return out;
}

void outputListNode(ListNode* p){
    if(nullptr == p ){
        return ;
    }
	cout << __func__ << endl;
    size_t sep = 10;
    size_t cnt = 0;
    while( p != nullptr){
        cout <<setiosflags(ios::left)<<setw(8);
        cout << p->val << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        p = p->next;
        cnt ++;
    }
    cout << endl;
}

//反转一个链表
ListNode* reverseList(ListNode* p ){
	if( p == nullptr){
		return p;
	}
	if( p->next == nullptr ){
		return p;
	}
	ListNode* pHead = p ;
	ListNode* pLast = nullptr ; 
	ListNode* pNext = nullptr ; 

	while( p != nullptr){
		pNext = p->next;
		p->next = pLast;
		pLast = p;
		p = pNext;
	}
	cout << __func__ << endl;
	outputListNode(pLast);
	return pLast;
}

ListNode* mergeList(ListNode* p1, ListNode* p2){
	if( p1 == nullptr){
		return p2;
	}
	if( p2 == nullptr){
		return p1;
	}

	ListNode* pHead = p1;

	ListNode* p1Next = p1->next;
	ListNode* p2Next = p2->next;
	while( p1 != nullptr && p2 != nullptr){
		p1->next = p2;
		p2->next = p1Next;

		if( p1Next == nullptr && p2Next != nullptr){
			p2->next = p2Next ; 
			break;
		}

		p1 = p1Next;
		p2 = p2Next;

		if( p1 != nullptr){
			p1Next = p1->next;
		}
		if( p2 != nullptr){
			p2Next = p2->next;
		}
	}

	return pHead;
}

ListNode*  ringRList(ListNode* p){
	if( p == nullptr ){
		return p;
	}
	if( p->next == nullptr ){
		return p;
	}
	if( p->next->next ==  nullptr ){
		return p;
	}
	// 1-> 2 也不用处理
	// 三步， 先用快、慢指针拆为两段
	// 再将后半断反转
	// 最后再合并
	
	ListNode* pFast = p ;
	ListNode* pSlow = p ;
	while( pFast->next != nullptr){
		pFast = pFast->next;
		if( pFast->next == nullptr){
			break;
		}
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	ListNode* pHalf = reverseList(pSlow->next);
	pSlow->next = nullptr;

	outputListNode(p);
	outputListNode(pHalf);

	p = mergeList(p, pHalf);
	cout << "mergeList " <<endl;
	outputListNode(p);

	return p;
}


int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int>  tmp = makeRandVec(num);
	outputVec(tmp);
	ListNode* p = makeList(tmp);
	outputListNode(p);

//	ListNode* p2 = makeList( makeRandVec(5 ) );
//	outputListNode(p2);
//	outputListNode(mergeList(p, p2));
	ringRList(p);
    return 0;
}
