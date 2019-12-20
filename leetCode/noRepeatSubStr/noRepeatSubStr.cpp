#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <map>  
#include <iomanip>
#include <memory>
#include <sys/time.h>
using namespace std;
//https://blog.csdn.net/kongkongkkk/article/details/77750745
//最长不重复子串

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
        cout <<setiosflags(ios::left)<<setw(2);
        cout << i << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        cnt ++;
    }
    cout << endl;
}

string makeRandStr(int num){
	string  out;
	out.reserve(num);
	for( int i = 0 ; i < num ; i++){
		out.push_back( rand()%14 + 'a');
	}
	return out;
}

//记录字段对应的最后出现的位置
//每次扫描新字符时，判断是否重复
int maxNoReat(const string& in){
	map<char, int>  mapChar2Index; //某个字符最后一次的index
	int maxLen = 0 ;
	int inSize = in.size();
	int maxIndex = 0 ;
	int start = 0 ; 

	vector<int>  dp(inSize);//每个位置对应的最长

	for( int k = 0 ; k < inSize ; k++){
		char t = in[k];
		auto it = mapChar2Index.find(t);
		if( it != mapChar2Index.end()){
			start = std::max(it->second+1,start);
		}
		mapChar2Index[t] = k;
		dp[k] = k - start +1;
		if( dp[k] > maxLen){
			maxLen = dp[k];
			maxIndex = k;
		}
	}
	outputVec(dp);
	cout << "maxLen:" << maxLen << " maxIndex:" << maxIndex << endl;
	cout << in.substr(maxIndex-maxLen+1, maxLen) << endl;
	return maxLen;
}

int main(int argc, char**argv){
    vector<int>  r2Sort;
    srand(Nowms());
    int num = 10;
    if( argc > 1 ){
        num = atoi(argv[1]);
    }
	string str = makeRandStr(num);
	cout << str << endl;
	maxNoReat(str);
    return 0;
}
