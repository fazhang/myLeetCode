#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include<queue>
#include <sys/time.h>
using namespace std;

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
     //   cout <<setiosflags(ios::left)<<setw(8);
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

void minHeap(const vector<int>& in , int k){
	cout << "in.size:"<<in.size()<<" k:" << k << endl;
	//小根堆
	priority_queue<int,vector<int>,greater<int> >q;
	//std::priority_queue<int>q;


	for( int i = 0 ; i < k ; i++  ){
		q.push(in[i]);
	}
	for( int i = k ; i < in.size(); i++){
		if(in[i] >= q.top()){
			q.pop();
			q.push(in[i]);
		}
	}
	cout << "q.size:"<<q.size() << " " <<  q.top() << endl;
	return;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int>  tmp = makeRandVec(num * 2 );
	outputVec(tmp);
	minHeap(tmp, num-1);
	sort(tmp.begin(), tmp.end());
	outputVec(tmp);
    return 0;
}
