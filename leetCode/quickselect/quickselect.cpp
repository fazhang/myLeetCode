#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
using namespace std;


//一个基于快排的 第N个 实现
//选一个基准数，跑一轮， 判断基数数位置
//

//做一个快速排序
//每次拿第一个值做p
//然后拿后面的做对比
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
    if( argc > 1 ){
    num = atoi(argv[1]);
    }
    for( size_t i = 0 ; i <num;  i++){
        r2Sort.push_back( rand()%19999);
    }
    outputVec(r2Sort);
    myqsort(r2Sort);
    cout << "<<<<<<<<<<<<<<<<<sort end <<<<<<<<<<<<<<<<<" << endl;
    outputVec(r2Sort);
    return 0;
}
