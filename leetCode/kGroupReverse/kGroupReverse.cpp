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
uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
void outputListNode(ListNode* p){
    if(nullptr == p ){
        return ;
    }
	cout << __func__ << endl;
    size_t sep = 10;
    size_t cnt = 0;
    while( p != nullptr){
        cout << p->val << "->";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        p = p->next;
        cnt ++;
    }
    cout << endl;
}
void outputVec(const vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
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

ListNode* kReverse(ListNode* p ,int k){
	if( k <= 1){
		return 0;
	}
	//空指针，或者只有一个节点，就不用处理了
	if( p == nullptr || p->next == nullptr){
		return 0;
	}

	//用双指针，每次向前走k 步，如果后续没有k个就不处理了
	ListNode dummy;
	dummy.next = p;


	ListNode* slow = p;
	ListNode* fast = slow;

	ListNode* last = &dummy;
	while( slow != nullptr){
		fast = slow;
		int m = k ;
		while( --m > 0 && fast != nullptr){
			fast = fast->next;
		}
		if( m !=  0 || fast == nullptr){
			break;
		}
		//要把slow -> fast 这一段的数据反转

		ListNode*  t = slow ;
		ListNode* pLast = nullptr ; 
		ListNode* pNext = nullptr ; 

		ListNode* head = t ;//第一个节点


		ListNode* fastnext = nullptr;
        if( fast != nullptr){
            fastnext = fast->next;
        }
		while( t != fastnext ){
			pNext = t->next;
			t->next = pLast;
			pLast = t;
			t = pNext;
		}
		
		slow = fastnext;
		head->next = fastnext;
		last->next = pLast;
		last = head;
	}

	return dummy.next;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
	int k = 2;
    if( argc > 2 ){
        num = atoi(argv[1]);
		k = atoi(argv[2]);
    }

	vector<int> tmp = makeRandVec(num);
	ListNode* p = makeList(tmp);
	outputListNode(p);
	for( int i = k ; i > 1; i --){
		ListNode* p = makeList(tmp);
		ListNode* p1 = kReverse(p, i);
		outputListNode(p1);
	}
    return 0;
}
