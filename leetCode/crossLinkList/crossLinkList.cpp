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
ListNode*  makeList(const vector<int>& in, ListNode* & tail ){
    ListNode pHead ;
    ListNode* pre = &pHead;
    for( auto i : in )
    {
        ListNode* p = new ListNode(i);
        pre->next = p ;
        pre = p ;
		tail = p; 
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

ListNode*  circleNode(ListNode* p ){
	if( p == nullptr || p->next == nullptr){
		return nullptr;
	}
	ListNode* slow = p;
	ListNode* fast = p;

	while( fast != nullptr){
		fast = fast->next;
		if( fast != nullptr){
			fast = fast->next;
		}
		slow = slow->next;
		if( slow == fast ){
			return slow;
		}
	}
	return nullptr;
}


ListNode* checkCrossNodeWithCircle(ListNode* p1, ListNode* p2, ListNode* c1, ListNode* c2){
	return nullptr;
}


ListNode* checkCrossNode(ListNode* p1, ListNode* p2){
	//check is cross
	if( p1 == nullptr || p2 == nullptr){
		return nullptr;//有一个空的，则无交点
	}
	ListNode* c1node	 = circleNode(p1);
	ListNode* c2node = circleNode(p2);
	if( (c1node == nullptr) ^ (c2node == nullptr)){
		return nullptr;
	}//异或为真，则说明一真一假

	if( (c1node != nullptr) && (c2node != nullptr)){
		return checkCrossNodeWithCircle(p1,p2, c1node, c2node);
	}

	/*
	int a = 0 ; 
	int b = 0 ; 
	int n = 0 ;
	*/

	ListNode* cross = nullptr;

	ListNode* a = p1;
	ListNode* b = p2;

	ListNode* longhead = nullptr;
	ListNode* shorthead = nullptr;
	while(a != nullptr && b != nullptr){
		if( a == b ){
			return a;
		}
		a = a->next;
		b = b->next;
	}
	//下面做个转换，将b 强制改成长的那一段
	if( a == nullptr && b == nullptr){
		return nullptr;
	}
	if( a != nullptr){
		longhead = p1;
		shorthead = p2;
	}
	if( b != nullptr){
		longhead = p2;
		shorthead = p1;
		a = b; 
		b = nullptr;
	}

	b = longhead;
	while( a != nullptr){
		a = a->next;
		b = b->next;
	}//这一段不用判断了
	a = shorthead;
	while( a != nullptr && b != nullptr){
		if( a == b ){
			return a;
		}
		a = a->next;
		b = b->next;
	}
	return nullptr;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int n1 = 10;
    int n2 = 5;
    int n3 = 5;
    if( argc > 3 ){
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
        n3 = atoi(argv[3]);
    }
	vector<int> t1 = makeRandVec(n1);
	vector<int> t2 = makeRandVec(n2);
	vector<int> t3 = makeRandVec(n3);
	ListNode* tail1, *tail2, *tail3;
	ListNode* p1 = makeList(t1, tail1);
	ListNode* p2 = makeList(t2, tail2);
	ListNode* p3 = makeList(t3, tail3);

	tail1->next = p3;
	tail2->next = p3;
	//tail3->next = p3;
	outputListNode(p1);
	outputListNode(p2);
	outputListNode(p3);

	ListNode*  p4 = checkCrossNode(p1,p2);
	outputListNode(p4);

    return 0;
}
