#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
using namespace std;


//查topK 与第K个

//[start, end]
void topK(vector<int>& in, vector<int>& out, int start, int end,  int K){

	//cout << "out.size:"<<out.size() << " start:"<< start<< " end:"<<end << " K:" << K << endl;
	if( start > end || K <= 0 ){
		return ;
	}
	int p = in[start];
	int i = start +1; 
	int j = end;

    for( ;  i < j && j > 0 && i < end;){
        if( in[i] <= p ){
            i++; continue;
        }
        if( in[j] >  p ){
            j--; continue;
        }
        std::swap(in[i],in[j]);
        i++;j--; //
    }
    i--; //最后一轮的i++ 处理后会多一步
    std::swap(in[i],in[start]);
	
	if( (i-start) <= K -1){
		for( int n  = start ; n <= i ; n++){
			out.push_back(in[n]);
		}
		topK(in,out, i+1, end, K-(i-start +1) ); 
	}else {
		topK(in,out,start, i-1, K);
	}

}

void KndNum(vector<int>& in, int& out, int start, int end, int K){
}

void qsort_inner(vector<int>& in ,int  start, int end ){
    if( start >= end ){
        return ; //一个值，已经不用排了
    }
    int p = in[start];
    int i = start+1 ; 
    int j = end ;
    for( ;  i < j && j > 0 && i < end;){
        if( in[i] <= p ){
            i++; continue;
        }
        if( in[j] >  p ){
            j--; continue;
        }
        std::swap(in[i],in[j]);
        i++;j--; //
    }
    i--; //最后一轮的i++ 处理后会多一步
    std::swap(in[i],in[start]);
    qsort_inner(in,start,i-1);
    qsort_inner(in,i+1,end);
}

void myqsort(vector<int>& in){
    qsort_inner(in,0, (in.size() -1));
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

int main(int argc, char**argv){
	vector<int>  r2Sort;
	srand(time(nullptr));
	int num = 10;
	int k = 5;
	if( argc > 2 ){
		num = atoi(argv[1]);
		k = atoi(argv[2]);
	}
    for( size_t i = 0 ; i <num;  i++){
        r2Sort.push_back( rand()%19999);
    }
	vector<int> topk;
	topK(r2Sort, topk, 0 , num-1, k);
	myqsort(r2Sort);
    outputVec(topk);
    outputVec(r2Sort);
    return 0;
}
