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

void outputListNode(ListNode* p){
    if(nullptr == p ){
        return ;
    }
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
vector<int> makeRandVec( int num, int mod=100){
    vector<int> out;
    out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return out;
}

ListNode*  insertHead(ListNode* in, int num){
	if(nullptr == in){
		return in;
	}
	ListNode* newNode = new ListNode(num);
	newNode->next = in;
	in = newNode;
	return  in;
}
ListNode*  insertTail(ListNode* in, int num){
	if(nullptr == in){
		return in;
	}
	ListNode* head;
	ListNode* newNode = new ListNode(num);
	while( in->next != nullptr){
		in = in->next;
	}
	in->next = newNode;
	return  head;
}


int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int> in = makeRandVec(num);
	ListNode* p = makeList(in);
	outputListNode(p);
	p = insertHead(p,1111);
	p = insertTail(p,2222);
	outputListNode(p);
    return 0;
}
