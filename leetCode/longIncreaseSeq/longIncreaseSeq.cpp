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

int findLongSubSeq(const vector<int>& in  ){
	int inSize = in.size();
	//dp[i]  表示 以i 为结尾的最长子序列的长度
	//迭代时， 要做 0 ~ i 逐渐判断
	vector<int> dp(inSize, 1 );
	int maxLen = 1 ; 
	//dp[0] 没啥好判断了

	for( int i = 1 ; i < inSize ; i++){
		for( int j = 0 ; j < i ; j++){
			if( in[i] >= in[j]){
				dp[i] = std::max(dp[i], dp[j] +1);
			}
		}
		maxLen = std::max(maxLen, dp[i]);
	}
	return maxLen;
}
int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	vector<int> in = makeRandVec(num,10);
	outputVec(in);
	cout << "maxLen:" << findLongSubSeq(in) << endl;
    return 0;
}
