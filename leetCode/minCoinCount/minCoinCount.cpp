//找零钱问题
#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <sys/time.h>

using namespace std;

vector<int> allCoin = {1,4,5,10};

//也要根据情况看， 有一些组合数据，可以使用贪心法
//即每一次取最大的
int findMinCoinCount(int total, vector<int>& out){
    vector<int>  dp(total+1); //尝试用其中一个后，剩下的最小值
    vector< vector<int> > allPlan(total+1);
    int planCnt = 0; //0~total 都有一个一堆数组
    dp[0] = 0;
    for( int i = 1 ; i <= total ;i++){
        dp[i] = total+1;//不可能超过这个值，除非还有五毛的
        int minIndex = i;
        int choseCoin = 0;
        for( int j = 0 ; j < allCoin.size(); j++){
            int minusCoin = i - allCoin[j];
            if( minusCoin < 0){
                continue;
            }
            if( dp[minusCoin] + 1 < dp[i]){
                dp[i] = dp[minusCoin] +1;
                minIndex = minusCoin; 
                choseCoin = allCoin[j] ; 
            }
        }
        allPlan[i] = allPlan[ minIndex] ;
        allPlan[i].push_back( choseCoin); //当前最优的策略
    }
    out.swap(allPlan[total]);
    return planCnt;
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
    
    int total = rand()%40;
    vector<int> out;
    findMinCoinCount(total, out);
    cout << "total:"<< total << " " << endl;
    outputVec(out);

    return 0;
}

