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

ListNode* listMerge(ListNode* p1, ListNode* p2){
    return nullptr;
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

vector<int> makeRandVec( int num, int mod=100){
    vector<int> out(num);
    for( int i = 0 ; i < num ; i++){
        out[i] = rand()%100;
    }
    cout << __func__ << endl;
    outputVec(out);
    return out;
}

ListNode*  makeList(const vector<int>& in){
    ListNode* pHead ;
    ListNode* pre = pHead;
    for( auto i : in )
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
    return pHead->next;
}


int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num1 = 10;
    int num2 = 20;
    if( argc > 2 ){
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
    }
    vector<int> link1 = std::move(makeRandVec(num1));
    vector<int> link2 = std::move(makeRandVec(num2));
    ListNode* p1 = makeList(link1);
    ListNode* p2 = makeList(link2);
    outputListNode(p1);
    outputListNode(p2);
    return 0;
}
