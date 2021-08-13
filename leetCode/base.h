//此文件用于公共的链表、树、vector 等生成
#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}

struct ListNode {
		public:
      int val;
      ListNode* next;
      ListNode(int x) { val = x; next = nullptr; }
      ListNode() {  next = nullptr; }
};

void outputVec(const std::vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
    for( auto i : in){
		//std::cout <<std::setiosflags(std::ios::left)<<std::setw(8);
        std::cout << i << " ";
        if( (cnt)%sep == 9){
         //   std::cout << std::endl;
        }
        cnt ++;
    }
    std::cout << std::endl;
}

void outputListNode(ListNode* p){
    if(nullptr == p ){
        return ;
    }
    size_t sep = 10;
    size_t cnt = 0;
    while( p != nullptr){
        std::cout <<std::setiosflags(std::ios::left)<<std::setw(8);
        std::cout << p->val << " ";
        if( (cnt)%sep == 9){
            std::cout << std::endl;
        }
        p = p->next;
        cnt ++;
    }
    std::cout << std::endl;
}

std::vector<int> makeRandVec( int num, int mod=100){
    std::vector<int> out;
    out.reserve(num);
    for( int i = 0 ; i < num ; i++){
		out.push_back(rand()%mod);
    }
	return out;
}

ListNode*  makeList(const std::vector<int>& in){
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





