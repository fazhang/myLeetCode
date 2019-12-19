#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>

//DP 解决子数组和问题
using namespace std;
int  findMaxSubArray(const vector<int>& in, int& start, int& end){
    int inSize = in.size();

    vector<int> dp(inSize);

    int maxIndex = 0 ;
    int max = dp[0] ;
    int lastStart = 0 ;
    int maxStart = 0 ;
    dp[0] = in[0];

    for( int i = 1 ; i < inSize; i++){
        int lastItemSum = dp[i-1] + in[i] ; 
        if( lastItemSum >= in[i] ){
            dp[i] = lastItemSum; 
        }else{
            dp[i] = in[i];
            lastStart = i;
        }
        //= 号用于处理0 的情况
        if( dp[i] >= max ){
            max = dp[i];
            maxIndex = i;
            maxStart = lastStart;
        }
    }

    start = maxStart;
    end = maxIndex;
    return max;
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

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
    for( size_t i = 0 ; i <num;  i++){
        r2Sort.push_back( rand()%50 - 25 );
    }
    outputVec(r2Sort);
    int start = 0 , end = 0 ;
    cout << "findMaxSubArray:" << findMaxSubArray(r2Sort, start,end) << endl;
    cout << "start:"<< start << " " << r2Sort[start]  << endl ;
    cout << " end:" << end  << " " << r2Sort[end]<< endl;
    return 0;
}
