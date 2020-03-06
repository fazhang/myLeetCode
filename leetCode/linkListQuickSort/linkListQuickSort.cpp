#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
using namespace std;

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
class ListNode {
	public:
		int val;
		ListNode* next;
		ListNode(int x) { val = x; next = nullptr; }
		ListNode() {  next = nullptr; }
};
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
void outputListNode(ListNode* p, ListNode* end  = nullptr, string msg = __func__ ){
    if(nullptr == p ){
        return ;
    }
    size_t sep = 10;
    size_t cnt = 0;
	cout << msg << endl;
    while( p != end ){
        //cout <<setiosflags(ios::left)<<setw(0);
        cout << p->val << "->";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        p = p->next;
        cnt ++;
    }
    cout << endl;
}
vector<int> makeRandVec( int num, int mod=100){

	mod = std::max(mod,100);
    vector<int> out;
    out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return out;
}

//如果ipre->next == jpre 有点特殊 
void myswap(ListNode* ipre, ListNode*& jpre ){
	if( ipre == jpre ){
		return ;
	}
	ListNode* i = ipre->next;
	ListNode* j = jpre->next;
	ListNode* inext = i->next;
	ListNode* jnext = j->next;

	if( ipre->next == jpre ){
		ipre->next = j;
		j->next = i ;
		i->next = jnext;
		jpre = ipre->next;
		return ;
	}


	ipre->next = j;
	j->next = inext;

	i->next = jnext;
	jpre->next = i; 

	//jpre = ipre->next;
}

//不包括end 
ListNode* quickSort( ListNode* p , ListNode* end){
	if( p == nullptr ){ return p; }
	if( p == end ){ return p; }
	if( p->next == end  ){ //只有一个元素了
		return p; 
	}
	ListNode* head = p ; int pval = p->val ;
	ListNode* i = p ; 
	ListNode* j = p->next;

	ListNode  dummy;
	dummy.next = p ;

	ListNode* ipre = &dummy;
	ListNode* jpre = p;
	int iindex = 0;
	int jindex = 1;

	for( ; i != end && j != end ; ){
		if( j->val < pval ){
			ipre = i; i = i->next;
			myswap(ipre,jpre);
			i = ipre->next;
			j = jpre->next;
		}
		jpre = j ;
		j = j->next;
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

void checkList(ListNode* p ){
	if( p == nullptr ){
		return ;
	}
	if( p->next == nullptr){
		return ;
	}
	int last = p->val;
	p = p->next;
	while(p != nullptr){
		if(p->val < last ){
			printf("error:%d %d \n", p->val , last);
		}
		last = p->val;
		p = p->next;
	}
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 5;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	//vector<int> tmp = {69,98,27,12,31,39};
	ListNode* p = makeList(makeRandVec(num,num*num));
	//ListNode* p = makeList(tmp);
	cout << "makeList" << endl;
	outputListNode(p);
	p = quickSort(p, nullptr);
	outputListNode(p);
	checkList(p);
    return 0;
}
