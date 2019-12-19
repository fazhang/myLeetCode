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

//两个有序的合并 
ListNode* listMerge(ListNode* p1, ListNode* p2){
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
			p1 = p1->next;
			head = head->next;
		}
		else{
			head->next = p2;
			p2 = p2->next;
			head = head->next;
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

void makeRandVec(vector<int>& out, int num, int mod=100){
	out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return ;
}

ListNode*  makeList(const vector<int>& in){
    ListNode* pHead ;
    ListNode* pre = pHead;
    for( auto i : in )
    {
		if( i > 100 || i < 0 ){
			cout << " what the fuck ? " << i << endl; 
		}
        ListNode* p = new ListNode(i);
		if( p == nullptr){
			cout << " what the fuck nullptr? " << i << endl; 
			exit(0);
		}
        if(pre == nullptr) {
            pHead = p;
        }
        else{
            pre->next = p ;
        }
        pre = p ;
    }
    return pHead->next;
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
    vector<int> link1 ; 
	// link1.resize(num1);
	//	cout << hex << (void*)(link1.data()) << " " << link1.size() <<  endl;
	//makeRandVec(link1,num1);
	int mod = 100;
	link1.reserve(num1);
    for( int i = 0 ; i < num1 ; i++){
		link1.push_back(rand()%mod);
    }
	cout << "link1:" << link1.size() << endl;
	//	cout << hex << (void*)(link1.data()) << " " << link1.size() <<  endl;
	vector<int> link2 ;  
	//	link2.resize(num2);
	//	cout << hex << (void*)(link2.data()) << " " << link2.size() <<  endl;
	makeRandVec(link2,num2);
	/*
	   link2.reserve(num2);
	   for( int i = 0 ; i < num2 ; i++){
	   link2.push_back(rand()%mod);
	   }
	   */
	cout << "link2:" << link2.size() << endl;

	std::sort(link1.begin(), link1.end());
	std::sort(link2.begin(), link2.end());

    ListNode* p1 = makeList(link1);
    ListNode* p2 = makeList(link2);
    cout << "p1\n " ;  outputListNode(p1);
    cout << "p2\n "; outputListNode(p2);
	//ListNode* p3 = listMerge(p1,p2);
	//outputListNode(p3);
    return 0;
}
