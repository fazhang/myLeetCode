#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
#include <map>
#include <stack>
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

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ret;
    if( head == nullptr){
        return ret;
    }
    stack<int> s;
    stack<int> index;
    map<int, int> index2val;
    int i= 0;
    while(head != nullptr){
        int val = head->val ;
        if( s.empty()){
            s.push(val);
            index.push(i);
            head = head->next;
            i++;
            continue;
        }

        if( val > s.top()){
            s.pop();
            int i = index.top();
            index.pop();
            index2val[i] =  val;
        }else{
            s.push(val);
            index.push(i);
            head = head->next;
            i++;
        }
    }
    ret.resize(i);
    for( auto s: index2val){
        ret[s.first] = s.second;
    }
    return ret;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
    vector<int> tmp1 = makeRandVec(num);
    outputVec(tmp1);
    ListNode* p = makeList(tmp1);
    vector<int> out = nextLargerNodes(p);
    outputVec(out);
    return 0;
}
